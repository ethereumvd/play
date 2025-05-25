package main

import (
	"fmt"
)

type bill struct {
	name string
	items map[string]float64
	tip float64
}

func newbill(nm string) bill {
	b := bill {
		name : nm,
		items : map[string]float64 {"pie":5.99, "cake":9.99},
		tip :0,
	}
	return b
}

//receiver function to format the bill
func (bl *bill) format() string {
	form_str := "bill breakdown :- \n"
	var total float64 = 0

	for item ,price := range bl.items {
		total += price
		form_str += fmt.Sprintf("%-10v ...$%v \n", item+":", price)
	}
	form_str += fmt.Sprintf("%-10v ...$%v \n","tip:", bl.tip)
	form_str += fmt.Sprintf("%-10v ...$%v","total:", total)
	return form_str
}

//here as we modify the map which gets passed by reference
//even if we dont pass bl by reference it actually changes contents of bl.items
func (bl bill) additem(item string, price float64) {
	bl.items[item] = price
}

//if we passed this by value it wont work as it did in additem()
func (bl *bill) updatetip(tip float64) {
	bl.tip = tip
}
//go automatically dereferences the bill pointer so we dont have to




func structss() {
	pointers()

	mybill := newbill("mario")
	fmt.Println(mybill)
	fmt.Println(mybill.format())
	mybill.updatetip(8)
	fmt.Println(mybill.format())
	mybill.additem("ice-cream", 11.99)
	fmt.Println(mybill.format())
}