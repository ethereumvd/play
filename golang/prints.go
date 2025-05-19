package main

import (
	"fmt"
)

func prints() {
	age := 21
	name := "ethereum"

	fmt.Print("lol \n")
	fmt.Print("lol")

	// %_ -> format specifiers
	fmt.Println(" age is", age, "name is ", name)
	fmt.Printf("age is %v , name is %v", age, name)
	fmt.Println()
	fmt.Printf("age is %q , name is %q", age, name)
	fmt.Println()
	fmt.Printf("age is of type %T , name is of type %T", age, name)
	fmt.Println()
	fmt.Printf("wow your score is %f ", 255.2524)

	// sprintf
	//saves the string , pretty weird
	var saved_string = fmt.Sprintf("this is saveprintf , age is %v", age)
	fmt.Println()
	fmt.Println("saved string is",saved_string)

}