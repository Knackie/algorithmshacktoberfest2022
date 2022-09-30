package sorting;

public class InsertionSorting {

	static void swap(int a[],int i , int j) {
		int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
	static void printArray(int a[]) {
		for(int e:a) {
			System.out.print(e+ "  ");
		}
	}

	static void insertionSort(int a[]) {
		int n=a.length;
		for(int i=1;i<n;i++) {
			int temp=a[i];
			int j=i-1;			
			for(;j>=0;j--) {
				if(temp<a[j]) {
					a[j+1]=a[j];
				}else {
					break;
				}
			}
			a[j+1]=temp;
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int arr []= {4,2,6,1,8,-66,33,22,111};
		insertionSort(arr);
		printArray(arr);
	}

}
