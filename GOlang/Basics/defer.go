package main
import("fmt")
//DEFER is LIFO. 
//Output will be 4 3 2 1 0
func main(){
	for i:=0;i<5;i++{
		defer fmt.Println(i)
	}
}