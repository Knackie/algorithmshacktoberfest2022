package sorting;

public class BubbleSorting {
	static void swap(int a[],int i,int j) {
		int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	static void bubbleSort(int arr[]) {
		int n=arr.length;
		for(int i=0;i<n-1;i++) {
			for(int j=0; j<n-i-1;j++) {
				if(arr[j]>arr[j+1]) {
					swap(arr,j,j+1);
				}
			}
		}
	}
	
	static void printArray(int a[]) {
		for(int e:a) {
			System.out.print(e+ "  ");
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int a[]=new int[] {9,5,2,-6,3,1,3};
		bubbleSort(a);
		printArray(a);
			

	}

}
