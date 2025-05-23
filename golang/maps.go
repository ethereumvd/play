package main

import (
	"fmt"
)

func mapss() {

	pkg_scope()

	menu := map[string]float64{
		"soup":           4.99,
		"pie":            7.49,
		"salad":          6.99,
		"toffee pudding": 9.99,
	}
	fmt.Println(menu["pi"])
	fmt.Println(menu["pie"])

	for key, val := range menu {
		fmt.Println(key, val)
	}

	phonebook := map[int]string {
		59614135 : "mario",
		68498493 : "luigi",
		94864436 : "ethereum",
		42345524 : "peach",
	}

	for phone, name := range phonebook {
		fmt.Println(name, phone)
	}
	//updating the map
	phonebook[59614135] = "yoshi"
	//adding another pair to the map
	phonebook[71514175] = "lol"

	for phone, name := range phonebook {
		fmt.Println(name, phone)
	}

}
