package string;

import java.util.Scanner;

public class ReplaceEByI {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		String name=sc.next();
		String res=" ";
		for(int i=0;i<name.length();i++) {
			if( name.charAt(i) == 'e') {
				res +="i";
			}else {
				res+=name.charAt(i);
			}
		}
		System.out.println(res);

	}

}
