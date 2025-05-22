package main

import (
	"fmt"
	"sort"
)

func loops() {

	x := 0
	for x < 3 {
		fmt.Println(x)
		x++
	}
	names := []string{"mario", "luigi", "poker", "ethereum", "yoshi"}

	for i := 0; i < len(names); i++ {
		fmt.Println(names[i])
	}

	for idx, name := range names {
		fmt.Printf("index is %v, value is %v \n", idx, name)
	}
	sort.Strings(names)

	for _, name := range names {
		fmt.Printf("value is %v \n", name)
		name = "new"
	}
	//if you dont want to use it use _ for that variable
	//changing the values inside for loop doesnt actually change the variable
	//it is a local copy for that for loop

	fmt.Println(names)
}
