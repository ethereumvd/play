package main

import (
	"fmt"
)

func updatename(name string) {
	fmt.Println(name)
	name = "werner"
}

func updatemenu(menu map[string]float64) {
	menu["coffee"] = 10.99
}

func pass_by_val() {
	mapss()

	//group A types -> strings , ints, bools, arrays, structs
	//non pointer values
	name := "tifo"
	updatename(name)
	//doesnt actually change the name
	fmt.Println(name)

	//group B types -> functions, maps, slices
	//it changes the actual value

	//these are called pointer wrapper values

	menu := map[string]float64 {
		"ice-cream" : 8.99,
		"pudding" : 7.49,
	}
	updatemenu(menu)
	for item, price := range menu {
		fmt.Println(item, price)
	}

}