#include <stdio.h>
#include <stdlib.h>

int* pigeonholeSort(int nums[], int size)
{
  int i, j, min = nums[0], max = nums[0], range;
  
  for (i = 1; i < size; i++)
  {
    if (nums[i] < min)
        min = nums[i];
    if (nums[i] > max)
        max = nums[i];
  }
  range = max - min + 1;

  int *tmp = (int *)malloc(sizeof(int) * range);
  for (i = 0; i < range; i++)
    tmp[i] = 0;
  for (i = 0; i < size; i++)
    tmp[nums[i] - min]++;
  j = 0;
  for (i = 0; i < range; i++)
  {
    while (tmp[i] > 0)
    {
      nums[j] = i + min;
      tmp[i]--;
      j++;
    }
  }
  return nums;
}
