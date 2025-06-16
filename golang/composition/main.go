package main

type Startable interface {
	Start()
}

func StartEngines(cars ...Startable) {
	for _, car := range cars {
		car.Start()
	}
}

func main() {

	myconvertible := Convertible{Engine{}, EnhancedTransmission{}, SteeringWheeel{}}
	mytruck := Truck{EnhancedEngine{}, Transmission{}, SteeringWheeel{}}

	StartEngines(myconvertible, mytruck)

	mytruck.SteerLeft()
	myconvertible.ShiftUp()
}
