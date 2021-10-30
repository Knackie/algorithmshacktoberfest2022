    #include <algorithm>
    #include <array>
    #include <iostream>
    #include <string>

    /*
        Bogosort Algorithm
        Works for arrays of any type 
    */
    template <typename T, size_t N>
    void bogosort(std::array<T,N> &arr) 
    {
        while (!std::is_sorted(arr.begin(), arr.end()))
        {
            std::random_shuffle(arr.begin(), arr.end());
        }
    }

    // Utility function to print contents of array
    template <typename T, size_t N>
    void print_array(std::array<T,N> const &arr)
    {
        std::cout << '[';
        for (const auto& element : arr) 
        {
            std::cout << element;
            
            if (element != arr.back())
            {
                std::cout << ", ";
            }
        }
        std::cout << ']' << std::endl;
    }

    // Utility function to sort and print array
    template <typename T, size_t N>
    void sort_and_print_array(std::array<T,N> &arr, std::string const &expected)
    {
        std::cout << "Expected: " << expected << std::endl;
        std::cout << "Got: ";
        bogosort(arr);
        print_array(arr);
        std::cout << std::endl;
    }

    int main() 
    {
        // Works for arrays of ints
        std::array<int, 5> arr1 {3, 7, 6, 1, 4};
        sort_and_print_array(arr1, "[1, 3, 4, 6, 7]");

        // Works for arrays of chars
        std::array<char, 4> arr2 {'f', 'r', 'b', 'i'};
        sort_and_print_array(arr2, "[b, f, i, r]");

        // Works for arrays of floats
        std::array<float, 6> arr3 {3.14159, 1.41421, 1.73205, 2.23606, 1.61803, -1};
        sort_and_print_array(arr3, "[-1, 1.41421, 1.61803, 1.73205, 2.23606, 3.14159]");

        // Works for arrays of string
        std::array<std::string, 3> arr4 {"bac", "bab", "abc"};
        sort_and_print_array(arr4, "[abc, bab, bac]");

        return 0;
    }