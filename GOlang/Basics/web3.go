//NOT WORKING

package main

import (
	"encoding/xml"
	"fmt"
	"io/ioutil"
	"net/http"
)

/*
STRUCTURE OF SitemapIndex XML we wanna use-
<sitemapindex>
	<sitemap>
		<loc>
			http://www.washingtonpost.com/news-politics-sitemap.xml
		</loc>
	</sitemap>
</sitemapindex>
*/

/*
Structure of Each News Type Obtained
<urlset xmlns="...">
	<url>
			<loc>... .html</loc>
			<n:news>
				<n:title>...</n:title>
				<n:keywords>...</n:keywords>
			</n:news>
	</url>
*/
type SitemapIndex struct {
	//Access <sitemap><loc> directly:
	Url []string `xml:"sitemap>loc"`
}

//Use CAPS variable first letter
type NewsStruct struct {
	Titles    []string `xml:"urlset>url>n:news>n:title"`
	Keywords []string `xml:"urlset>url>n:news>n:keywords"`
}

func main() {
	resp, _ := http.Get("https://www.washingtonpost.com/news-sitemap-index.xml")
	bytes, _ := ioutil.ReadAll(resp.Body)
	resp.Body.Close()

	var site SitemapIndex
	xml.Unmarshal(bytes, &site)

	for i := 0; i < len(site.Url); i=i+2 {
		//To print every url:
		//fmt.Println(site.Url[i])
		fmt.Println(string(site.Url[i]))

		resp, _ := http.Get(string(site.Url[i]))
		bytes, _ := ioutil.ReadAll(resp.Body)
		resp.Body.Close()

		fmt.Println(string(bytes))
		var news NewsStruct
		xml.Unmarshal(bytes, &news)
		//fmt.Println("Unmarshal successful!")
		fmt.Println(len(news.Titles))

		for j := 0; j < len(news.Titles); j++ {
			fmt.Println("\nTitle: " + news.Titles[j])
			fmt.Println("\nKeywords: " + news.Keywords[j])
		}
	}
}
