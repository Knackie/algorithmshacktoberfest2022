package golang

import (
	"testing"
	"reflect"
)

func TestInsertionSort(t *testing.T){
	tcs := []struct {
		in []int
		want []int
	}{
		{
			in: []int{5, 2, 6, 3, 1, 4},
			want: []int{1, 2, 3, 4, 5, 6},
		},
	}
	for _, tc := range tcs {
		got := insertionSort(tc.in)
		if !reflect.DeepEqual(tc.want, got) {
			t.Errorf("want %v, but got %v\n", tc.want, got)
		}
	}
}