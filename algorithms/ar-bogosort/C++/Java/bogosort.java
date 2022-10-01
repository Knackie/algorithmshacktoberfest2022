import java.util.ArrayList;
import java.util.Collections;

public class Bogosort {
    
    public static void main(String[] args) {
        boolean flag = false;
        int count = 0;
        ArrayList<Integer> list = new ArrayList<Integer>();
        list.add(0);
        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);
        list.add(5);
        // list.add(6);
        // list.add(7);
        // list.add(8);
        // list.add(9);

        while(!flag){
            System.out.println(count);
            Collections.shuffle(list);
            for(int i = 0; i < list.size()-1; i++){
                if(list.get(i) > list.get(i+1)){
                    count += 1;
                    break;
                }else if(i+1 == list.size()-1){
                    flag = true;
                }
            }
        }
        


        System.out.println(list);
        System.out.println("It took " + count + " times to put into order");
    }
}