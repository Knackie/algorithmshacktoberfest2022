package string;

public class convertIntegerToRoman {
	
	public static String IntegerToRoman(int num) {
		  int Num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
	      String roman[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
	      String Roman="";
	      StringBuilder sb=new StringBuilder();
	      for(int i=Num.length-1;i>=0;i--) {
	    	  while(num>=Num[i]) {
	    		  sb.append(roman[i]);
	    		  num-=Num[i];
	    	  }
	      }
	      return sb.toString();
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int num=18;
		System.out.println(IntegerToRoman(num));
	}
}
