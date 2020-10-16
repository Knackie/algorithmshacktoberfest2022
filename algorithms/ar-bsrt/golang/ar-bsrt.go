package main

import "fmt"

func main() {
	unsorted := []int{100, 29, 0, 12, 8, 28, 11, 38, 102, 1, 28, 3}
	fmt.Printf("Pre bubble sort: %v\n", unsorted)
	sorted := bubbleSort(unsorted)
	fmt.Printf("Post bubble sort: %v\n", sorted)
}

func bubbleSort(nums []int) []int {
	size := len(nums)
	sorted := false

	for !sorted {
		swappedVal := false
		for i := 1; i < size; i++ {
			if nums[i-1] > nums[i] {
				nums[i], nums[i-1] = nums[i-1], nums[i]
				swappedVal = true
			}
		}
		if !swappedVal {
			sorted = true
		}
		size = size - 1
	}

	return nums
}
