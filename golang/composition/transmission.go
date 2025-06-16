package main

import "fmt"

type Transmissionn interface{
	ShiftUp()
	ShiftDown()
}

type Transmission struct{}

func (t Transmission) ShiftUp() {
	fmt.Println("Switching up gear...")
}

func (t Transmission) ShiftDown() {
	fmt.Println("Switching down gear...")
}

type EnhancedTransmission struct{}

func (et EnhancedTransmission) ShiftUp() {
	fmt.Println("Shifting up gear fasttt....")
}

func (et EnhancedTransmission) ShiftDown() {
	fmt.Println("Shifting down gear fasttt....")
}
