package main

import (
	"fmt"
	"strings"
	"sort"
)

func stl() {

	fmt.Println("hello")
	greetings := "hello world, this is ethereum, hello again"
	fmt.Println(strings.Contains(greetings, "hell"))
	//contains returns true if its present

	new_greetings := strings.ReplaceAll(greetings, "hello", "hi")
	fmt.Println(new_greetings)
	//returns a string with replaced keyword

	new_greetings = strings.ToUpper(new_greetings)
	fmt.Println(new_greetings)

	fmt.Println(greetings)
	idx := strings.Index(greetings, "or")
	fmt.Println(idx)
	//first index that matches given substring

	new_slices := strings.Split(greetings, " ")
	fmt.Printf("%T , %v", new_slices, new_slices)
	fmt.Println()
	fmt.Println(new_slices[1])
	//slices the string between specified string ans returns a slice

	//sort package
	ages := []int{2, 12, 41, 12 ,4, 5, 68, 43, 2}
	sort.Ints(ages)
	fmt.Println(ages)

	idx = sort.SearchInts(ages, 30)
	fmt.Println(idx)

	names_ := []string{"mario", "luigi", "yoshi", "ethereumv", "vd", "pager"}
	sort.Strings(names_)
	fmt.Println(names_)
	fmt.Println(sort.SearchStrings(names_, "maria"))


}
