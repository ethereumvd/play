package main

import (
	"fmt"
	"sync"

)

func task(id int, wg* sync.WaitGroup) {

	defer wg.Done()
	fmt.Println("doing task" , id)

}

func main() {

	var wg sync.WaitGroup

	for i := range 10 {
		wg.Add(1)
		go task(i, &wg)
		//runs these functions concurrently

		go func(i int) {
			fmt.Println("hello")
		}(i)
	}

	// time.Sleep(time.Second * 2)
	//this is a issue because irl we dont know how much time will take
	wg.Wait()
	fmt.Println("all goroutines finished")
	//waitgroup acts as a counter
	//it makes the execution of a function wait until the counter resets to 0
	//that is all the goroutines have been completed
	//make sure to add and Done the waitgroup otherwise program will die lol
}
