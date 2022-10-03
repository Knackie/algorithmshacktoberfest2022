package matrix;

public class RotateSquareMatrix90clockwise {
	
	public static void printMatrix(int a[][]) {
		int n=a.length;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				System.out.print(a[i][j]+"   ");
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
	
	public static void rotateMatrix(int a[][]) {
		int n=a.length;
		transposeOfMatrix(a);
		for(int i=0;i<n;i++) {
			for(int j=0;j<n/2;j++) {
				int swap=a[i][j];
				a[i][j]=a[i][n-j-1];
				a[i][n-j-1]=swap;
			}
		}
	}


	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int matrix[][]= {
				{1,2,3,4},
				{5,6,7,8},
				{9,10,11,12},
				{13,14,15,16},
	};
		printMatrix(matrix);
		rotateMatrix(matrix);
		System.out.println("After rotating the matrix : ");
		printMatrix(matrix);

}
}
