#include <iostream>
#include <vector>

void BubbleSort(int array[], int size) {
  bool isSwap;
  
  do {
    isSwap = false;
    for (int i = 0; i < (size - 1); i++) {
      if (array[i] > array[i+1]) {
        std::swap(array[i], array[i+1]);
        isSwap = true;
      }
    }
  } while (isSwap);
}

void BubbleSortString(std::vector<std::string> &vec) {
  bool swap;

  if (vec.size() == 0) {
    return;
  }
  
  do {
    swap = false;
    for (int i = 0; i < vec.size() - 1; i++) {
      if (vec[i] > vec[i+1]) {
        vec[i].swap(vec[i+1]);
        swap = true;
      }
    }
  } while (swap);
}

void print(std::vector<std::string> &v) {
  std::cout << "[";
  bool first = true;
  for (auto x : v) {
    if (!first) {
      std::cout << ", ";
    }
    std::cout << x;
    first = false;
  }
  std::cout << "]";
  std::cout << std::endl;
}


void print(int array[], int size) {
  for (int i = 0; i < size; i++) {
    std::cout << array[i] << " ";
  }
  std::cout << "\n";
}


int main() {
  std::vector<std::string> v, x, y;

  v = {"emma", "dora", "ruth", "ziegellaub", "eichler"};
  x = {"emma"};
  y = {};
   
  std::cout << "Testing BubbleSort with Array of Strings: \n";
  std::cout << "Bubble Sort: ";
  
  BubbleSortString(v);
  std::cout << "Expected: [dora, eichler, emma, ruth, ziegellaub]" << std::endl;
  print(v);
   
  BubbleSortString(x);
  std::cout << "Expected: [emma]" << std::endl;
  print(x);
   
  BubbleSortString(y);
  std::cout << "Expected: []" << std::endl;
  
  print(y);

  int values[6] = {7, 2, 3, 8, 9, 1};
  std::cout << "\nTesting BubbleSort with Array of ints: \n";
  std::cout << "The unsorted values are: ";
  print(values, 6);
  
  BubbleSort(values, 6);
  
  std::cout << "The sorted values are: ";
  print(values, 6);
  std::cout << "\n";
  
  return 0;
}
