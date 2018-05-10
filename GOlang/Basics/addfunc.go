package main
import ("fmt")

//Both x and y have float64 type
func add(x,y float64) float64{
	return x+y
}

//Here, both a and b have type string
func concat(a,b string) (string,string){
	return a,b
}
func main(){
	//Type Inferencing
	num1,num2:=3.2,4.2

	w1,w2:="Hey","There"
	
	fmt.Println(add(num1,num2))
	fmt.Println(concat(w1,w2))

}