package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {

	f, err := os.Open("sample.txt")

	if err != nil {
		panic(err)
	}

	fileinfo, err := f.Stat()
	if err != nil {
		panic(err)
	}

	fmt.Println(fileinfo)

	buf := make([]byte, fileinfo.Size())

	d, err := f.Read(buf)
	if err != nil {
		panic(err)
	}

	for i := 0; i < len(buf); i++ {
		fmt.Println(string(buf[i]))
	}

	fmt.Println(string(buf))

	fmt.Println("data: ", d)
	fmt.Println(fileinfo.Size())

	data , err := os.ReadFile("sample.txt")//only loads once temporarily
	//unlike the buffer which stoes i ina bye array
	if err != nil {
		panic(err)
	}
	fmt.Println(string(data))

	dir , err := os.Open(".")
	if err!= nil {
		panic(err)
	}

	//read and write to another file

	sourcefile, err := os.Open("sample.txt")
	if err!= nil {
		panic(err)
	}

	destfile, err := os.Create("sample2.txt")
	if err != nil {
		panic(err)
	}

	reader := bufio.NewReader(sourcefile)
	writer := bufio.NewWriter(destfile)

	for {
		b, err := reader.ReadByte()
		if err != nil {
			if err.Error() != "EOF" {
				panic(err)
			}
			break
		}
		e := writer.WriteByte(b)
		if e != nil {
			panic(e)
		}
	}

	writer.Flush()


	defer destfile.Close()
	defer sourcefile.Close()
	defer dir.Close()
	defer f.Close()
}
