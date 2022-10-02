//Extract maximum numeric value from a given  
//  i/p: jjkkjk1221jnjkk44kj32kjkjnk657645jknk
//  o/p : 657645

package string;

import java.util.Scanner;

public class extractMaximum {
	static int extractMaximumValue(String str) {
		int num=0,res=0;
		for(int i=0;i<str.length();i++) {
			if (Character.isDigit(str.charAt(i))) {
				num=num*10 + (str.charAt(i)-'0');
			}else {
				res=Math.max(res, num);
				num=0;
			}
		}
		return Math.max(res, num);
	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String name=sc.next();
		System.out.println(extractMaximumValue(name));
	}

}
