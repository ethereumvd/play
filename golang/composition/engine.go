package main

import "fmt"

type Enginee interface {
	Start()
}

type Engine struct{}

func (e Engine) Start() {
	fmt.Println("Starting Engine...")
}

type EnhancedEngine struct {}

func (ee EnhancedEngine) Start() {
	fmt.Println("Starting Engine fasttt...")
}