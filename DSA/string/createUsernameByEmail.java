package string;

import java.util.Scanner;

public class createUsernameByEmail {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String email=sc.next();
		String username=" ";
		for(int i=0;i<username.length();i++) {
			if(email.charAt(i)=='@') {
				break;
			}else {
				username+=email.charAt(i);
			}
		}
		System.out.println(" Email is "+email+" and "+"username is "+username);
	}

}
