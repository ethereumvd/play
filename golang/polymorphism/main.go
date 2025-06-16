package main

import "fmt"

type Purchasable interface {
	CalculatePrice() float64
}

func CalculateCartPrice(products ...Purchasable) float64{
	total := 0.0
	for _, prd := range products {
		total += prd.CalculatePrice()
	}
	return total
}


func main() {

	myshirt := Shirt{ProductDetails{Price:60.7, Brand: "Polo"}, "XL", "Blue"}
	mymonitor := Monitor{ProductDetails{Price : 600.9, Brand: "LG"}, 1900, "4K"}
	mywine := Wine{ProductDetails{Price:900, Brand:"idk"}, "1990", "Dont know"}

	mycart := []Purchasable{mymonitor, myshirt, mywine}

	fmt.Println("total price of items is :- ")
	fmt.Println(CalculateCartPrice(mycart...))
}