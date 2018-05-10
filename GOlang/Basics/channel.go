package main

import (
	"fmt"
	"time"
)

func main() {
	c := make(chan string)
	go count("sheep", c)

/*
	for {
		msg,open := <-c //Will cause halting problem, use open

		if !open {
			break
		}
		fmt.Println(msg)
	}
ALITER : */

	for msg := range c{
		fmt.Println(msg)		
	}

}

func count(thing string, c chan string) {
	for i := 1; i <= 5; i++ {
		c <- thing
		time.Sleep(time.Millisecond * 500)
	}
	close(c)
}
