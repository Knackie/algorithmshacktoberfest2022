using System;
using System.Linq;

class min_arr
{
    static void Main()
    {
        int[] test_array = { 3, 12, 16, 1, -1, -5, 2, -10, 18, 0 };

        int min_number = test_array.Min();
        Console.WriteLine(min_number);

    }
}