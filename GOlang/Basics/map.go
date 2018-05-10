package main

import "fmt"

func main(){
	grades := make(map[string]float32)

	grades["Travis"] =42
	grades["Jane"]=93

	fmt.Println(grades)

	TravisGrades :=grades["Travis"]
	fmt.Println(TravisGrades)

	delete(grades,"Jane")
	fmt.Println(grades)

	for k,v := range grades{
		fmt.Println(k,":",v)
	}
}