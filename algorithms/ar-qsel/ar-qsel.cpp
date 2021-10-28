#include <iostream>
#include <algorithm>

using namespace std;

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int quickselect(int *arr, int n, int k) {
    int left = 0, right = n - 1;
    while (left < right) {
        int pivot = partition(arr, left, right);
        if (pivot == k) {
            return arr[pivot];
        } else if (pivot < k) {
            left = pivot + 1;
        } else {
            right = pivot - 1;
        }
    }
    return arr[left];
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 5;
    cout << quickselect(arr, 10, k) << endl;
    return 0;
}
