package string;

public class convertStringToInteger {
	 public static int StringToInteger(String s) {
	        long n=0;
	        String inp=s.trim();
	        if(inp.length()==0) return 0;
	        int chars=0;
	        boolean flag=false;
	        if(inp.charAt(0)=='-') flag=true;
	        
	        for(int i=0;i<inp.length();i++){
	            if(i==0 && (inp.charAt(i)=='-' || inp.charAt(i)=='+'))
	                continue;
	            if(chars>10) break;
	            if(inp.charAt(i)-48 >=0 && inp.charAt(i)-48<=9){
	                n=n*10 + (inp.charAt(i)-48);
	                if(n==0 && (inp.charAt(i)-48)==0)
	                    continue;
	                else
	                    chars++;
	            }
	            else 
	                break;
	        }
	        if(flag) n=-n;
	        if(n>Integer.MAX_VALUE) return Integer.MAX_VALUE;
	        else if(n<Integer.MIN_VALUE) return Integer.MIN_VALUE;
	        return (int)n;
	    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		String str="-4323325 with words";
		System.out.println(StringToInteger(str));
	}

}
 