package string;
import java.util.Stack;

public class Parenthesis {
	
	static boolean parenthesisEqual(String s) {
		if(s.isEmpty()) {
			return true;
		}
		Stack<Character> stk= new Stack<>();
		for(int i=0;i<s.length();i++)
		{
			char current=s.charAt(i);
			if(current=='{' || current=='(' || current=='[')
			{
				stk.push(current);
			}
			if(current=='}' || current==')' || current==']')
			{
				if(stk.isEmpty()) {
					return false;
				}
				char last=stk.peek();
				if(current==')' && last=='(' || current=='}' && last=='{' ||
						current==']' && last=='[') {
					stk.pop();
				}else {
					return false;
				}
			}
		}
		if(stk.isEmpty()) {
			return true;
		}else {
			return false;
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String str="()[]{}";
//		parenthesisEqual(str);
		System.out.println(parenthesisEqual(str));
	}

}
