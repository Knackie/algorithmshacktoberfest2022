package matrix;

public class SearchElementInMatrix {

	
		// TODO Auto-generated method stub
		public static boolean SearchElement(int a[][],int key) {
			int n=a.length;
			int row=0, col=n-1;
			
			while(row<n && col>=0) {
				if(a[row][col]==key) {
					return true;
				}else if (key>a[row][col]){
					row++;
				}else {
					col--;
				}
			}
			return false;
		}	
		
		public static void main(String[] args) {

		int matrix[][]={
				{1,2,3,4},
				{12,13,15,17},
				{14,16,18,21},
				{22,28,31,32}
		};
		int key=32;
//		printMatrix(matrix);
//		SearchElement(matrix);
		System.out.println(SearchElement(matrix,key));
	}
}

