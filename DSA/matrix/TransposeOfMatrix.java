package matrix;

public class TransposeOfMatrix {
	public static void printMatrix(int a[][]) {
		int n=a.length;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				System.out.print(a[i][j]+ "  ");
			}
			System.out.println();
		}
		
	}

	public static void transposeOfMatrix(int a[][]) {
		int n=a.length;
		for(int i=0;i<n;i++) {
			for(int j=i+1;j<n;j++) {
				int swap=a[i][j];
				a[i][j]=a[j][i];
				a[j][i]=swap;
			}
			
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int matrix[][] = {
				{1,2,3},
				{4,5,6},
				{7,8,9}
		};
		printMatrix(matrix);
		transposeOfMatrix(matrix);
		System.out.println("After transpose of matrix : ");
		printMatrix(matrix);
		

	}

}
