package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)


func promptoptions(b bill) {
	reader := bufio.NewReader(os.Stdin)
	opt, _ := getinput("a - add item \ns - save bill \nt - add tip", reader)

	switch opt {

	case "a":
		fmt.Println("you chose a")
		name, _ := getinput("item name:", reader)
		price, _ := getinput("price of the item :", reader)

		p, err := strconv.ParseFloat(price, 64)

		if err != nil {
			fmt.Println("price must be a number !!")
			promptoptions(b)
		}
		b.additem(name, p)
		fmt.Println("item added: ", name, "$"+price)
		promptoptions(b)

	case "t":
		fmt.Println("you chose t")
		tip, _ := getinput("enter tip: ", reader)

		t, err := strconv.ParseFloat(tip, 64)
		if err != nil {
			fmt.Println("tip must be a number !!")
			promptoptions(b)
		}
		b.updatetip(t)
		fmt.Println("added tip :" , "$"+tip)
		promptoptions(b)

	case "s":
		fmt.Println("you chose s")
		b.savebill()
		fmt.Println("you saved bill :-", b.name)

	default:
		fmt.Println("invalid input")
		promptoptions(b)

	}

}

func main() {
	user_input()

	mybill := createbill()
	promptoptions(mybill)

}