package main

import (
	"fmt"
)

//i can use all the functions, vars and stuff that are in package main
//i can also use any functions made here otherwhere as well

var scores []int = []int{99, 68, 90, 78}
//this has to be declared at the root level otherwise we can access it from other files

func pkg_scope(){

	funcss()

	for _,point := range points {
		fmt.Println(point)
	}

	showscores()
	//showscores is defined in functions.go and is used here

}