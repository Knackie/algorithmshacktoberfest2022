// C program to find the prime numbers
// between a given interval
#include <stdio.h>

// Function for print prime
// number in given range
void primeInRange(int L, int R)
{
	int i, j, flag;

	// Traverse each number in the
	// interval with the help of for loop
	for (i = L; i <= R; i++) {

		// Skip 0 and 1 as they are
		// neither prime nor composite
		if (i == 1 || i == 0)
			continue;

		// flag variable to tell
		// if i is prime or not
		flag = 1;

		// Iterate to check if i is prime
		// or not
		for (j = 2; j <= i / 2; ++j) {
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}

		// flag = 1 means i is prime
		// and flag = 0 means i is not prime
		if (flag == 1)
			printf("%d ", i);
	}
}

// Driver Code
int main()
{
	// Given Range
	int L = 1;
	int R = 10;

	// Function Call
	primeInRange(L, R);

	return 0;
}
