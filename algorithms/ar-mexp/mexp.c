// Modular Exponential in C
#include<stdio.h>
int power(int x,int y,int p);
/* Iterative Function to calculate (x^y)%p in O(log y) */
int power(int x, int y, int p)
{
	int res = 1;	 // Initialize result
	x = x % p; // Update x if it is more than or equal to p
	if (x == 0) return 0; // In case x is divisible by p;
	while (y > 0)
	{
		// If y is odd, multiply x with result
		if (y & 1)
			res = (res*x) % p;
		// y must be even now
		y = y>>1; // y = y/2
		x = (x*x) % p;
	}
	return res;
}
int main()
{
	int x = 2,y=5,p=13;
	clrscr();
	printf("Power is %d",power(x, y, p));
	return 0;
}
