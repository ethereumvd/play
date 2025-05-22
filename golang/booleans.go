package main

import (
	"fmt"
)

func main() {
	age := 49

	fmt.Println(age >= 50)
	fmt.Println(age != 90)
	fmt.Println(age > 2)

	if age > 30 {
		fmt.Println("age is less than 30")
	}  else if age < 50{
		fmt.Println("age is less than 50")
	}

	names := []string{"mario", "luigi", "poker", "ethereum", "yoshi", "joker", "peach"}

	for idx, name := range names {
		if idx == 1 {
			fmt.Printf("skipping index %v \n" , idx)
			continue
		}
		if(idx == len(names) - 2) {
			fmt.Printf("breaking at index %v \n", idx)
			break
		}
		fmt.Println(name)
	}

}