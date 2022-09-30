package sorting;


public class selectionSorting {

	static void swap(int a[],int i ,int j) {
		int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}

	static void printArray(int a[]) {
		for (int e :a) {
			System.out.print(e + "  ");
		}
		System.out.println();
		System.out.println();
	}
	
	static void SelectionSort(int a[]) {
		int n=a.length;
		for(int i=0;i<n-1;i++) {
			int min=i;
			for (int j=i+1;j<n;j++) {
				if(a[j]<a[min]) {
					min=j;
				}
			}
			swap(a,min,i);
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int arr []= {4,2,6,1,8,-66,33,22,111};
		printArray(arr);
		SelectionSort(arr);
		printArray(arr);
	}

}
