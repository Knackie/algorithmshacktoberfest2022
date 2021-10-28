import java.util.Scanner;


class Main {
  /*
   * Orders an array from smallest to biggest.
   * 
   * @param double[] array
   * 
   * @returns double[]
   */
  public static int[] ascendingOrder(int[] array) {
    for (int i = 0; i < array.length; i++) {
      for (int j = 0; j < array.length; j++) {
        if (array[i] < array[j]) {
          int num = array[i];
          array[i] = array[j];
          array[j] = num;
        }
      }
    }
    System.out.println("Array in ascending order");
    return array;
  }
  /*
   * Prints an array list
   */
  public static void printArray(int[] array){
    for(int i=0; i < array.length; i++){
      System.out.print(array[i]+" ");
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    System.out.print("Enter array Size: ");
    Scanner sc = new Scanner(System.in);
    int size = sc.nextInt();
    //Creates array with user size
    int[] array = new int[size];

    //Adds user number input to the array
    System.out.println("Input numbers:");
    for(int i = 0; i < size; i++){
      int n = 0;
      n = sc.nextInt();
      array[i] = n;
    }

    System.out.println("Array inputed");
    printArray(array);
    printArray(ascendingOrder(array));

  }
}