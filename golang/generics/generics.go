package main

import "fmt"


//example of a generic
func printslice[T any](sl []T, name T) {
	for _, item := range sl {
		fmt.Println(item)
	}
	fmt.Println(name)
}

type stack[T any] struct {
	elements []T
}

func main() {
	ints := []int{1, 5, 23, 4}
	names := []string{"ethereunvd", "golang"}
	mystack := stack[int]{[]int{1, 2}}
	mystack2 := stack[string]{[]string{"hello", "world"}}
	fmt.Println(mystack)
	fmt.Println(mystack2)

	printslice(ints, 1)
	printslice(names, "hello")

}