package sorting;

public class mergeSorting {
	
	static void merge(int a[],int l, int mid, int h) {
		int i=l, j=mid+1,k=l;
		int b[]=new int [a.length];
		while(i<=mid && j<=h) {
			if(a[i]<=a[j]) {
				b[k]=a[i];
				i++;
			}else {
				b[k]=a[j];
				j++;
			}
			k++;
		}
		if(i>mid) {
			while(j<=h) {
				b[k]=a[j];
				k++; j++;
			}
		}else {
			while(i<=mid) {
				b[k]=a[i];
				i++;k++;
			}
		}
		for(i=l;i<h;i++) {
			a[i]=b[i];
		}
	}
	
	static void mergeSort(int a[] ,int l,int h) {
		if(l<h) {
			int mid=(l+h)/2;
			mergeSort(a,l,mid);
			mergeSort(a,mid+1,h);
			merge(a,l,mid,h);
		}
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int arr []= {4,2,6,1,8,-66,33,22,111};
		
		mergeSort(arr,0,arr.length-1);
		for(int e:arr) System.out.print(e +"  ");
		

	}

}
