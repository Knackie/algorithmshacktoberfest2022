import java.util.*;
import java.lang.*;
import java.io.*;
  
class exponentiation_by_squaring{
    public static void main(String[] args){
        long base=5;
        long exp=10;
        long ans=exponentiation(base, exp);
        System.out.println(ans);
    }
  
    static long exponentiation(long base, long exp){  
        long ans=1;
        while(exp>0){
            if(exp%2==1)
                ans=ans*base;
                base=base*base;
                exp=exp/2;
        }
        return ans;
    }
}