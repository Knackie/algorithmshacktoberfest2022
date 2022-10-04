// C# program of Quick Select
using System;

class GFG
{
	
	// partition function similar to quick sort
	// Considers last element as pivot and adds
	// elements with less value to the left and
	// high value to the right and also changes
	// the pivot position to its respective position
	// in the readonly array.
	static int partitions(int []arr,int low, int high)
	{
		int pivot = arr[high], pivotloc = low, temp;
		for (int i = low; i <= high; i++)
		{
			// inserting elements of less value
			// to the left of the pivot location
			if(arr[i] < pivot)
			{		
				temp = arr[i];
				arr[i] = arr[pivotloc];
				arr[pivotloc] = temp;
				pivotloc++;
			}
		}
		
		// swapping pivot to the readonly pivot location
		temp = arr[high];
		arr[high] = arr[pivotloc];
		arr[pivotloc] = temp;
		
		return pivotloc;
	}
	
	// finds the kth position (of the sorted array)
	// in a given unsorted array i.e this function
	// can be used to find both kth largest and
	// kth smallest element in the array.
	// ASSUMPTION: all elements in []arr are distinct
	static int kthSmallest(int[] arr, int low,
								int high, int k)
	{
		// find the partition
		int partition = partitions(arr,low,high);

		// if partition value is equal to the kth position,
		// return value at k.
		if(partition == k)
			return arr[partition];
			
		// if partition value is less than kth position,
		// search right side of the array.
		else if(partition < k )
			return kthSmallest(arr, partition + 1, high, k );
			
		// if partition value is more than kth position,
		// search left side of the array.
		else
			return kthSmallest(arr, low, partition - 1, k );		
	}
	
	// Driver Code
	public static void Main(String[] args)
	{
		int[] array = {10, 4, 5, 8, 6, 11, 26};
		int[] arraycopy = {10, 4, 5, 8, 6, 11, 26};
				
		int kPosition = 3;
		int length = array.Length;
		
		if(kPosition > length)
		{
			Console.WriteLine("Index out of bound");
		}
		else
		{
			// find kth smallest value
			Console.WriteLine("K-th smallest element in array : " +
								kthSmallest(arraycopy, 0, length - 1,
														kPosition - 1));
		}
	}
}

// This code is contributed by halmoside
