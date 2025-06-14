package main

import (
	"fmt"
	"math/rand"
	"sync"
	"runtime"
	"time"
)


func repeatfunc[T any, K any](done <-chan K, fn func() T) <-chan T {
	channel := make(chan T)

	go func() {
		defer close(channel)

		for {
			select {
			case <-done :
				return
			default:
				channel <- fn()
			}
		}

	}()

	return channel
}

func take[T any, K any] (done <-chan K, stream <-chan T, n int) <-chan T {
	out := make(chan T)

	go func() {
		defer close(out)

		for i := 0; i < n; i++ {
			select {
			case <- done :
				return
			default :
				out <- <-stream
			}
		}

	}()

	return out
}

func primefinder(done <- chan bool, randintstream <-chan int) <-chan int {

	isprime := func(n int) bool {
		if n <= 1 { return false }
		for i := 2; i*i <= n; i++ {
			if n % i == 0 {
				return false;
			}
		}
		return true;
	}


	primes := make(chan int)

	go func() {
		defer close(primes)

		for {
			select {
			case <-done:
				return
			case num := <-randintstream :
				if isprime(num) {
					primes <- num
				}
			}
		}
	}()

	return primes
}

func fanin[T any, K any](done <-chan K, channels ...<-chan T) <-chan T {
	var wg sync.WaitGroup

	outstream := make(chan T)
	defer close(outstream)

	transfer := func(channel <-chan T) {
		defer wg.Done()
		for i := range channel{
			select {
			case <-done :
				return
			case outstream <- i :
			}
		}
	}

	for _, channel := range channels {
		wg.Add(1)
		go transfer(channel)
	}

	go func() {
		wg.Wait()
		defer close(outstream)
	}()
	//putting this wait inside a goroutine is esential
	//because otherwise it would block fanin func to sent the output channel
	//in which case there wount be a receiver for outstream
	//hence it would panic and end
	//this causes a deadlock
	//fanin trying to write to outstream
	//wait preventing it be blocking execution there

	return outstream
}

func main() {

	starttime := time.Now()

	done := make(chan bool)
	genrandom := func() int {return rand.Intn(1000)}
	randintstream := repeatfunc(done, genrandom)

	CPUCount := runtime.NumCPU()

	fannedoutchans := make([]<-chan int, CPUCount)

	for i := 0; i < CPUCount; i++ {
		fannedoutchans[i] = primefinder(done, randintstream)
	}

	fannedinstream := fanin(done, fannedoutchans...)
	finalstream := take(done , fannedinstream, 20)

	for i := range finalstream {
		fmt.Println(i)
	}

	close(done)
	fmt.Println(time.Since(starttime))
}