/*
  This algorithm is based on the linear searching algorithm
  Time complexity for the algorithm is 0(N) where N is the number of elements in the array (Worst Case)
  Space complexity is 0(1)
*/

#include <iostream>
using namespace std;

int linearSearch(int arr[], int key, int size) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == key) {
      return i;
    }
  }

  return -1;
}

int main() {
  int arr[] = {1, 6, 2, 4, 4, 9, 78, 7, 78};
  int size = sizeof(arr)/sizeof(arr[0]);

  int key = 78;
  
  int res = linearSearch(arr, key, size);
  if (res == -1) {
    cout << "Key not found" << endl;
  } else {
    cout << "The element " << key << " was found at the index of " << res << endl;
  }
  return 0;
}