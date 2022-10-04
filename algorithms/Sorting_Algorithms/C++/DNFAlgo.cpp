// DNF : Dutch National Flag algo is used to sort an array consisting three different types elements

#include <bits/stdc++.h>
using namespace std;

void DNF(int nums[], int n)
{

        int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {

        if (nums[mid] == 0)
        {
            swap(nums[mid], nums[low]);
            mid++;
            low++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);

            high--;
        }
    }
}
// Function to print array arr[]
void printArray(int arr[], int arr_size)
{
    // Iterate and print every element
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
}

// Driver Code
int main()
{
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    DNF(arr, n);

    printArray(arr, n);

    return 0;
}