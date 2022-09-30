package sorting;

public class QuickSorting {
	
	static void swap(int a[],int i , int j) {
		int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	
	static int partition(int a[],int l ,int h) {
		int i=l,j=h;
		int pivot=a[l];
		while(i<j) {
			while(a[i]<=pivot) i++;
			while(a[j]>pivot) j--;
			if(i<j) {
				swap(a,i,j);
			}
			
		}
		swap(a,l,j);
		return j;
	}

	static void quickSort(int a[],int l, int h) {
		if(l<h) {
			int pivot=partition(a,l,h);
			quickSort(a,l,pivot-1);
			quickSort(a,pivot+1,h);
		}
		
	}
	static void printArray(int a[]) {
		for(int e: a) {
			System.out.print(e+"  ");
		}
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int arr[]= {2,4,6,2,-97,8,-33,2,55,-33};
		quickSort(arr,0,9);
		printArray(arr);
	}

}







