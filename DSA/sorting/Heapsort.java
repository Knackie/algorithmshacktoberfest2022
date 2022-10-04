package sorting;
import java.util.Random;
import java.util.Scanner;

 class HeapSort {
    static int count = 0;

    public static void main(String[] args) {
//        Some random array
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the elements of array");
        int n = s.nextInt();
        int[] a = new int[n];
        System.out.println("Enter the elements one by one");
        for (int i = 0; i < n; i++) a[i] = s.nextInt();
        heapSort(a);
        System.out.println("The sorted array is :");
        for (int i : a) { System.out.print(i + " "); }
        System.out.println("\nThe time taken is approx :" + count);

//        Part 2
        System.out.println("Part 2");
        genAns();
    }

    static void heapify(int[] a, int i, int e) {
        int li = i;
        if (2 * i + 1 <= e && a[li] < a[2 * i + 1]) {
            li = 2 * i + 1;
        }
        if (2 * i + 2 <= e && a[li] < a[2 * i + 2]) {
            li = 2 * i + 2;
        }
        count+=2;
        if (li != i) {

            int t = a[li];
            a[li] = a[i];
            a[i] = t;
            heapify(a, li, e);

        }


    }

    static void buildHeap(int[] a, int e) {

        for (int i = (e - 1) / 2; i >= 0; i--) {
            heapify(a, i, e);

        }

    }

    static void heapSort(int[] a) {
        buildHeap(a, a.length - 1);

        for (int i = a.length - 1; i > 0; i--) {
            int t = a[0];
            a[0] = a[i];
            a[i] = t;
            heapify(a, 0, i - 1);
        }

    }

    static void genAns() {
        System.out.printf("%-15s%-15s%-15s%-15s%-15s\n", "Array Size", "Ascending", "Descending", "Random", "nlogn Value");
        for (int i = 4; i <= 256; i *= 2) {
            int[] asc = new int[i],
                    des = new int[i],
                    rand = new int[i];
            Random r = new Random(4);
//           Creating some random arrays ascending,descending and sorted respectively
            for (int ind = 0; ind < i; ind++) {
                asc[ind] = ind;
                des[ind] = i - ind;
                rand[ind] = r.nextInt();
            }
            count = 0;
            heapSort(asc);
            int ac = count;

            count = 0;
            heapSort(des);
            int dc = count;

            count = 0;
            heapSort(rand);
            int rn = count;
          
            int nlogn = i * (int) (Math.log10(i) / Math.log10(2));
            System.out.printf("%-15s%-15s%-15s%-15s%-15s\n", i, ac, dc, rn, nlogn);
        }
    }
}
