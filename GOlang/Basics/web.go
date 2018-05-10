/*//------------------------------------///
Goto Web Browser.
Type 'localhost:8000' in URLbar
*///------------------------------------///

package main
import ("fmt" 
		"net/http")

func index_handler(w http.ResponseWriter,r *http.Request){
	
	//Multiline 
	fmt.Fprintf(w,`
		<h1>First GO Webpage!</h1>
		<h2>By Xan</h2>
	`)

	fmt.Fprintf(w,"<h3> Hey %s ssup?","user")
}


func main(){
	http.HandleFunc("/",index_handler)
	http.ListenAndServe(":8000",nil)
}