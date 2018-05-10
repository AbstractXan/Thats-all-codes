package main
import "fmt"

//Pointer handling same as C++
func main(){
	x := 15
	a := &x //Memory Address
	fmt.Println(a)
	fmt.Println(*a)
	*a=5
	fmt.Println(x)
	*a=*a**a
	fmt.Println(x)
	fmt.Println(*a)
}