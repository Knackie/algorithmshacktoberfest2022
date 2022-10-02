import java.util.*;

public class seive {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number");
        int num = sc.nextInt();
        boolean[] a = new boolean[num];
       
        for (int i = 0; i< a.length; i++) {
           a[i] = true;
        }
        for (int i = 2; i< Math.sqrt(num); i++) {
           if(a[i] == true) {
              for(int j = (i*i); j<num; j = j+i) {
                 a[j] = false;
              }
           }
        }
        System.out.println("List of prime numbers upto given number are : ");
        for (int i = 2; i< a.length; i++) {
           if(a[i]==true) {
              System.out.println(i);
           }
        }
     }
  }

