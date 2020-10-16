package main

import "fmt"

func main() {
	searchNums := []int{100, 3, 4, 88, 99, 1, 14, 44}

	tempSmallest := searchNums[0]
	for _, num := range searchNums {
		if num < tempSmallest {
			tempSmallest = num
		}
	}

	fmt.Printf("min: %d\n", tempSmallest)
}
