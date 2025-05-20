package main

import (
	"fmt"
)

func arr_slice() {

	var ages [5]uint8 = [5]uint8{3, 4, 5} //arrays cant change their length
	lol := [7]uint8{0, 9}
	names := [4]string{"mario", "yoshi", "blake"}
	names[1] = "luigi"
	names[3] = "ethereum"
	fmt.Println(names)
	fmt.Println(lol, len(lol), cap(lol))
	fmt.Println(ages, len(ages))
	fmt.Println("hello")

	//slices -> can change their length
	var scores = []int{100, 50, 60}
	fmt.Println(scores, len(scores), cap(scores))
	scores = append(scores, 85)
	scores = append(scores, 88)
	fmt.Println(scores, len(scores), cap(scores))

	rangeone := names[1:2] //doesnt include the last index(or range)
	rangetwo := names[:3]
	rangethree := names[2:]
	//these ranges are just slices at the end
	fmt.Println(rangeone)
	fmt.Println(rangetwo)
	fmt.Println(rangethree)

}
