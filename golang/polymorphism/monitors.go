package main

type Monitor struct {
	ProductDetails
	Size int64
	Resolution string
}

func (m Monitor) CalculatePrice() float64 {
	electronicstax := 0.30
	return m.Price * (1 + electronicstax)
}
