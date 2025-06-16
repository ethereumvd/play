package main

type Shirt struct {
	ProductDetails
	Size  string
	Color string
}

func (s Shirt) CalculatePrice() float64 {
	clothingtax := 0.20
	clothingdiscount := 0.10
	return s.Price * (1 + clothingtax - clothingdiscount)
}
