package main

import (
	"os"
	"fmt"
)

func (b *bill) savebill() {

	data := []byte(b.format())
	err := os.WriteFile("bills/"+b.name+".txt", data, 0644)

	if err != nil {
		panic(err)
	}

	fmt.Println("bill was saved to file")

}