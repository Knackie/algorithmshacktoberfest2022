 package string;

import java.util.Scanner;

public class findCumulativeLength {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int totLength=0;
		Scanner sc=new Scanner(System.in);
		int size=sc.nextInt();
		String array[]=new String [size];
		for(int i=0;i<size;i++) {
			array[i]=sc.next();
			totLength +=array[i].length();
			System.out.println("total length is "+totLength);
		}
		System.out.println("finally total length is "+totLength);
	}

}
