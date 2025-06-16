package main

import "fmt"

type SteeringWheeel struct {}

func (s *SteeringWheeel) SteerRight() {
	fmt.Println("Turning Right...")
}

func (s *SteeringWheeel) SteerLeft() {
	fmt.Println("Turning Left...")
}