public class Main
{
	public static void main(String[] args) {
        int array[] = new int[]{105, 91, -848, 0, 42, -120};
        int min = getMin(array);
        System.out.println("Minimum is: "+min);
    }
 
  public static int getMin(int[] array){ 
    int min = array[0]; 
    for(int i=1;i<array.length;i++){ 
      if(array[i] < min){ 
        min = array[i]; 
      } 
    } 
    return min; 
  } 
}
