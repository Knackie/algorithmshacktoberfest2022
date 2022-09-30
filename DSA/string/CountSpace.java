package string;
import java.util.Scanner;

public class CountSpace {

	public static void countSpaceInString(String str) {
		int space=0; 
		int n=str.length();
		for(int i=0;i<n-1;i++) {
			char ch=str.charAt(i);
				if(ch== ' ') {
					space++;
				}
			
		}
		System.out.println("total space is "+space);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the String  ");
		String str=sc.nextLine();
		countSpaceInString(str);
		
		
	}

}
