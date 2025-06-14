package main

// import (
// 	"fmt"
// 	"time"
// )

// func slicetochan(nums []int) <-chan int{
// 	out := make(chan int)

// 	go func() {
// 		for _, n := range nums {
// 			out <- n
// 		}
// 		close(out)
// 	}()
// 	return out
// }

// func squarenums(inp <-chan int) <-chan int {
// 	out := make(chan int)

// 	go func() {
// 		for n := range inp {
// 			//this will keep reading inp channel until its closed
// 			//so its important to close that channel othwerise problems
// 			out <- n * n
// 		}
// 		close(out)
// 	}()
// 	return out
// }

// func main() {

// 	nums := []int{1, 2, 3, 4, 5, 6}

// 	chan1 := slicetochan(nums)

// 	chan2 := squarenums(chan1)

// 	time.Sleep(time.Second*2)

// 	for n := range chan2 {
// 		fmt.Println(n)
// 	}
// }