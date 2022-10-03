package string;

public class lexicographically {
	
	static int lexicographically2(String s1, String s2) {
		for(int i=0;i<s1.length() && i<s2.length();i++) { 
			if((int)s1.charAt(i)== (int)s2.charAt(i)) {
				continue;
			}
			else {
				return (int)s1.charAt(i)-(int)s2.charAt(i);
			}
		
		}
		if(s1.length() <s2.length()) {
			return (s1.length()-s2.length());
		}
		else if(s1.length() > s2.length()) {
			return (s1.length() - s2.length());
		}
		else {
			return 0;
		}
		
	}
	
	public static void main(String[] args) {
		String s1="Ravi";
		String s2="Ravi";
		String s3="Shyam";
		String s4="ABC";
		
		System.out.println(s1.compareTo(s2));
		System.out.println(s1.compareTo(s3));
		System.out.println(s1.compareTo(s4));
		System.out.println(s2.compareTo(s4));
		
		System.out.println(lexicographically2(s1,s2));
		System.out.println(lexicographically2(s1,s3));
		System.out.println(lexicographically2(s1,s4));
		System.out.println(lexicographically2(s2,s4));
	}
}
