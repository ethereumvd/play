package main

import (
	"fmt"
	"bufio"
	"strings"
	"os"
)

func getinput(prompt string, r *bufio.Reader) (string, error) {
	fmt.Println(prompt)
	input, err := r.ReadString('\n')
	return strings.TrimSpace(input),  err
}

func createbill() bill {

	//create a reader object that will read from stdin
	reader := bufio.NewReader(os.Stdin)
	name ,_ := getinput("Create new bill name", reader)

	bl := newbill(name)
	fmt.Println("created new bill ", bl.name)
	return bl

}


func user_input() {
	structss()

	// mybill := createbill()
	// promptoptions(mybill)
	// fmt.Println(mybill)
}