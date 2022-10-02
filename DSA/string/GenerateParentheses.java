package string;

import java.util.ArrayList;
import java.util.List;

public class GenerateParentheses {
	
	 public static List<String> generateParenthesis(int n) {
	        List<String> result=new ArrayList<>(); 
	        findAll("(",1,0,result,n);
	        return result;
	    }
	    static void findAll(String current, int openB, int closeB,List<String> result,int n){
	        if(current.length()==2*n){
	            result.add(current);
	            return;
	        }
	        if(openB<n )findAll (current+"(", openB+1,closeB, result,n);
	        if(closeB<openB) findAll(current+")",openB,closeB+1,result,n);
	    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n=3;
		System.out.println(generateParenthesis( n));

	}

}
 