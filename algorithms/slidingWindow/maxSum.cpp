#include<bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int maxSum(int arr[], int k, int n, int &start, int &end)
{
  if (k > n)
  {
    return -1;
  }
  int maximumSum = 0;
  int currentSum = 0;
  // Compute the initial sum of first K elements.
  for (int i=0;i<k;i++)
  {
    currentSum += arr[i];
  }
  maximumSum = currentSum;
  start = 0;
  end = k - 1;
  // Sliding the window and updating maximumSum
  for (int i=k;i<n;i++)
  {
    // Add the rightmost element to the window and
    // discard the leftmost element from the window
    currentSum += arr[i] - arr[i-k];
    if (currentSum > maximumSum)
    {
      maximumSum = currentSum;
      start = i - k + 1; // the window starts one ahead of the element that was removed from the left
      end = i; // the window goes upto the position of the newly added element from the right
    } 
  }
  return maximumSum;
}

// driver code
int main()
{
  int start = 0;
  int end = 0;
  int arr[] = {6, 2, -1, 9, 1, -2};
  int k = 3;
  int n = (sizeof(arr)/sizeof(*arr));
  int maxsum = maxSum(arr, k, n, start, end);
  cout << "The maximum sum is " << maxsum;
  cout << " from position " << start << " till " << end << endl;
  return 0;
}