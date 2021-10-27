class Main {
  /*
   * Orders an array from smallest to biggest.
   * 
   * @param double[] array
   * 
   * @returns double[]
   */
  public static double[] ascendingOrder(double[] array) {
    for (int i = 0; i < array.length; i++) {
      for (int j = 0; j < array.length; j++) {
        if (array[i] < array[j]) {
          double num = array[i];
          array[i] = array[j];
          array[j] = num;
        }
      }
    }
    System.out.println("Array in ascending order");
    return array;
  }
  /*
   * Orders an array from biggest to smallest.
   * 
   * @param double[] array
   * 
   * @returns double[]
   */
  public static double[] descendingOrder(double[] array) {
    for (int i = 0; i < array.length; i++) {
      for (int j = 0; j < array.length; j++) {
        if (array[i] > array[j]) {
          double num = array[i];
          array[i] = array[j];
          array[j] = num;
        }
      }
    }
    System.out.println("Array in descending order");
    return array;
  }

  public static void main(String[] args) {
    double[] numbers = { 0.19, 1, 0.17, 0.3, 0.234, 0.43, 0.1, 0.11, 0.98, 0.01, 0.3, 0.76, 1.1 };
    double[] ordered = ascendingOrder(numbers);

    for (int i = 0; i < ordered.length; i++) {
      System.out.print(ordered[i] + " ");
    }

  }
}