package main

import (
	"fmt"
	"time"

)

// func add(result chan int, num1 int , num2 int) {
// 	time.Sleep(time.Second)
// 	result <- num1 + num2
// }

func task(done chan bool) {
	defer func() { done <- true }()
	fmt.Println("executing code logic inside task")
}

func main() {

	chan1 := make(chan int, 2)
	chan2 := make(chan string, 2)

	go func() {
		chan1 <- 1
	}()

	go func() {
		chan2 <- "from channel 2"
	}()

	for i := range 3 {
		i++
		select {
		case chanval1 := <-chan1 :
			fmt.Println(chanval1)
		case chanval2 := <-chan2 :
			fmt.Println(chanval2)
		default:
			fmt.Println("no data receieved from either channels")
		}
	}

	// intchan := make(chan int)
	blchan := make(chan bool)

	go task(blchan)
	<-blchan
	//this is a block
	//code below wont reach it

	emailchan := make(chan string, 3)

	emailchan <- "exmple"
	emailchan <- "anotherexample"
	emailchan <- "lol"

	fmt.Println(<-emailchan)
	fmt.Println(<-emailchan)
	//as this is buffered channel i can avail not receiving all tha i sent
	//because it wont block anything

	// go add(intchan, 2, 4)

	fmt.Println("hello from main")

	time.Sleep(time.Second * 2)
	// messagechan := make(chan string)
	// messagechan <- "ping"
	// msg := <- messagechan
	// fmt.Println(msg)
}
