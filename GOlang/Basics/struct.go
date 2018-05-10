package main
import "fmt"

const u16bitmax float64 = 65535
type car struct{
	accel uint16
	brake uint16
	steering int16
	top_speed float64
}

//kmph function for car struct
//(Similar to class functions in C++)
func (c car) kmph() float64{
	return float64(c.accel)*(c.top_speed)/u16bitmax
}

//Changing STRUCT values
//Using Pointer
func (c *car) new_top_speed(newspeed float64){
	c.top_speed = newspeed
}


//Changing struct value
//Without pointer reciever
func newer_speed(c car,newspeed float64) car{
	c.top_speed = newspeed
	return c
}
func main(){
	
	//Values could be assgined to struct types like this too-
	a_car := car{accel: 5}
	fmt.Println("car{accel:5}\nSets other values to zero")
	fmt.Println(a_car)

	//Refining resets the values
	a_car = car{231,0,134,255.0}
	fmt.Println("\ncar{231,0,134,255.0}")
	fmt.Println(a_car)

	//a_car.accel are accesible
	fmt.Println("\na_car.accel")
	fmt.Println(a_car.accel)

	//kmph() function for struct car
	//Similar to Class Functions in C++
	fmt.Println("\na_car.kmph()\nkmph() is a function for struct car")
	fmt.Println(a_car.kmph())
	
	//Changing top_speed parameter using pointer reciever function
	a_car.new_top_speed(64.0)
	fmt.Println("\na_car.new_top_speed(64.0)\nChanging struct values using reciever funtion")
	fmt.Println(a_car)

	//Changing top_speed parameter without using pointer recievers
	a_car=newer_speed(a_car,500.0)
	fmt.Println("\na_car=newer_speed(a_car,500.0)\nChanging struct values without reciever functions")
	fmt.Println(a_car)
}