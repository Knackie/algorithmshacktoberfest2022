import java.util.Random;

public class Bogosort {
    public static void main(String[] args) {
        int[] unsortedArray = { 4, 2 , 3, 5};
        printArray("Unsorted array: ", unsortedArray);
        int[] sortedArray = sort(unsortedArray);
        printArray("Sorted array: ", sortedArray);
    }

    private static void printArray(String label, int[] array) {
        System.out.println(label);
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + "\t");
        }
        System.out.println();
    }

    private static int[] sort(int[] array) {
        while (!sortedArray(array)) {
            scramble(array);
        }
        return array;
    }

    private static void scramble(int[] array) {
        Random r = new Random();
        for (int i = array.length - 1; i > 0; i--) {
            int newIndex = r.nextInt(i);
            int aux = array[newIndex];
            array[newIndex] = array[i];
            array[i] = aux;
        }
    }

    private static boolean sortedArray(int[] array) {
        for (int i = 1; i < array.length; i++) {
            if (!(array[i] >= array[i - 1])) {
                return false;
            }
        }
        return true;
    }
}