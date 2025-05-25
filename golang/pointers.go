package main

import (
	"fmt"
)

func newname(name *string) {
	fmt.Println("before :", *name)
	*name = "werner"
}

func pointers() {
	pass_by_val()

	name := "timo"
	nameptr := &name
	fmt.Println(&name, nameptr, &nameptr)
	fmt.Println("value at nameptr is ", *nameptr)

	newname(nameptr)
	fmt.Println("after :" ,*nameptr)

}