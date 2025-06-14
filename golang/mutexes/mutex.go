package main

import (
	"fmt"
	"sync"
)

type posts struct {
	views int
	lck sync.Mutex
}

func (p *posts) inc(wg *sync.WaitGroup) {
	defer func() {
		wg.Done()
		p.lck.Unlock()
	}()

	p.lck.Lock()
	p.views+=1
}

func main() {

	myposts := posts{views: 0}
	var wg sync.WaitGroup

	for i := 0; i < 100; i++ {
		wg.Add(1)
		myposts.inc(&wg)
	}
	wg.Wait()

	fmt.Println(myposts.views)
}