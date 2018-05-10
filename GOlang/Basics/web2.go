//Tutorial for unmarshalling
//https://tutorialedge.net/golang/parsing-xml-with-golang/
//Check web3.go for a cleaner and concise version
//
package main

import (
	"encoding/xml"
	"fmt"
	"io/ioutil"
	"net/http"
)

/*
STRUCTURE OF XML we wanna use-
<sitemapindex>
	<sitemap>
		<loc>
			http://www.washingtonpost.com/news-politics-sitemap.xml
		</loc>
	</sitemap>
</sitemapindex>
*/

//STRUCTURE OF SITEMAP wrt Data Structure
type SitemapIndex struct {

	//Slice of location
	Sitemaps []Location `xml:"sitemap"`
}

//STRUCTURE OF LOCATION
type Location struct {
	Url string `xml:"loc"`
}

//Converts to string
func (l Location) String() string {
	return fmt.Sprintf(l.Url)
}
func main() {
	//Get response
	resp, _ := http.Get("https://www.washingtonpost.com/news-sitemap-index.xml")
	bytes, _ := ioutil.ReadAll(resp.Body)
	//string_body := string(bytes)
	//fmt.Println(string_body)
	resp.Body.Close()

	var site SitemapIndex
	xml.Unmarshal(bytes, &site)

	//SitemapIndex , Location are struct names.
	//We use the names site (type:SitemapIndex) and its variable Sitemaps (type: []Locations) to use its Url (type: string)
	for i := 0; i < len(site.Sitemaps); i++ {
		fmt.Println(site.Sitemaps[i].Url)
	}
}
