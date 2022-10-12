package main

import "fmt"

func linearsearch(datalist []int, key int) bool {
	for _, item := range datalist {
		if item == key {
			return true
		}
	}
	return false
}

func main() {
	items := []int{32, 13, 123, 56, 34}
	// If element found print element found
	if linearsearch(items, 56) {
		fmt.Println("Element found.")
	} else {
		fmt.Println("Element not found.")
	}
}
