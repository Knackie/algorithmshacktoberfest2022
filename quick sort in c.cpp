#include <stdio.h>

int partition(int a[], int l, int h)
{  int t,i=l+1;
  do
    {
      while (a[i] <= a[l])//first element as pivot element
	{
	  i++;
	}
      while (a[h] > a[l])
	{
	  h--;
	}

      if (i< h)
	{
	  t = a[h];
	  a[h] = a[i];
	  a[i] = t;
	}
    }
  while (i < h);


  t = a[l];
  a[l] = a[h];
  a[h] = t;

return h;
  
}
void quickSort(int a[], int l, int h)
{
    int pi; // pivot element sorted Index

    if (l < h)
    {
        pi = partition(a, l, h); 
        quickSort(a, l, pi - 1);  // sort left subarray 
        quickSort(a, pi + 1, h); // sort right subarray
    
}
}

int main ()
{
  int i, a[6],p;
  printf("Enter array elements:\n");
  for (i = 0; i < 6; i++)
    {
      scanf ("%d", &a[i]);
    }
    quickSort(a, 0, 5);
    printf("Sorted array(by quick sort):\n");
    for (p = 0; p < 6; p++)// printing sorted array
{
    printf ("%d ", a[p]);
}
  return 0;

}



