public class Main {

  public static int getSmallestValue(int[] values) {
      if (values.length < 1) {
          throw new IllegalArgumentException("The provided array must contains at least one element");
      }

      int smallest = values[0];

      for (int value : values) {
          if (value < smallest) {
              smallest = value;
          }
      }

      return smallest;
  }

  public static void main(String[] args) {
      int[] values = new int[] { 105, 91, -848, 0, 42, -120 };
      System.out.println("Smallest integer: " + getSmallestValue(values));
  }

}
