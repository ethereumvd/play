package main

import (
	"fmt"
	"math"
	"strings"
)

//used the points slice to dmonstrate package scope in pkg_scope.go
var points []int  = []int{1, 2, 3, 4}

func showscores() {
	for _,score := range scores {
		fmt.Printf("score is %v \n",score)
	}
	//to demonstrate how i can use variables from differnt files
	//scores is a slice defined in pkg_scope.go
}

func saygreeting(name string) {
	fmt.Printf("good morning %v \n", name)
}

func saygreetings(names []string) {
	for _,name := range names {
		saygreeting(name)
	}
}

func saygreetingsdiff(names []string, f func(string)) {
	for _,name := range names {
		f(name)
	}
}

func circle_area(radius float64)  float64{
	return math.Pi * radius * radius
}

func getinitials(namee string) (string , string) {
	namee = strings.ToUpper(namee)
	names := strings.Split(namee, " ")
	var initials []string
	for _,name := range names {
		initials = append(initials, name[:1])
	}
	if len(initials) > 1 {
		return initials[0] , initials[len(initials)-1]
	}
	return initials[0], "_"
}

func funcss() {

	fmt.Println("hello")
	saygreeting("mario")
	names := []string{"mario", "luigi", "ethereumv", "peach", "yoshi"}

	saygreetings(names)
	saygreetingsdiff(names, saygreeting)
	//just pass the saygreeting func dont do saygreeting()
	// that will invoke the function there

	area1 := circle_area(2.3)
	area2 := circle_area(10)
	fmt.Printf("circle1 area is %0.3f and circle2 is %0.4f \n", area1, area2)

	fn, ln := getinitials("anna bowser")
	fmt.Println(fn, ln)

	fn, ln = getinitials("mark")
	fmt.Println(fn, ln)

	fn, ln = getinitials("ethereum vd lol")
	fmt.Println(fn, ln)

}