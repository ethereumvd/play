package main

type Wine struct {
	ProductDetails
	Age string
	Type string
}

func (w Wine) CalculatePrice() float64 {
	stateliquortax := 0.30
	liqourtax := 0.34
	return w.Price*(1 + stateliquortax + liqourtax)
}