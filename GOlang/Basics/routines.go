//Example program for WaitGroup,Defer,Panic,Cleanup
//https://blog.golang.org/defer-panic-and-recover

package main
import (
	"fmt"
	"time"
	"sync"
)

func cleanup(){
	defer wg.Done()
	if r:=recover();r!=nil{
		fmt.Println("Recovered in cleanup",r)
	}
}
//WaitGroup
var wg sync.WaitGroup
func say(s string){

	//defer wg.Done() //Runs at the function end
	defer cleanup() //Recovers functions if panicked
	for i:=0;i<3;i++{
		fmt.Println(s)
		time.Sleep(time.Millisecond*100) 

		if i==2{
			panic("oh dear, 'tis a 2!")
		}
	}
	//Using wg.Done() here could be risky if we get stuck in loops/errors
}

func main(){
	//Add 1 to wait groups before every go routine
	wg.Add(1)
	go say("Hey")
	wg.Add(1)
	go say("There")


	//WaitGroup Counter should not run into -ve values
	wg.Add(1)
	go say("hi")
	wg.Wait()
}	