#include<stdio.h>

void bubble_sort( int A[ ], int n ) {

    int temp;
    for(int k = 0; k< n-1; k++) {
        for(int i = 0; i < n-k-1; i++) {         // (n-k-1) is for ignoring comparisons of elements which have already been compared in earlier iterations
            if(A[ i ] > A[ i+1] ) {
                temp = A[ i ];                  // here swapping of positions is being done.
                A[ i ] = A[ i+1 ];
                A[ i + 1] = temp;
            }
        }
    }
}

int main()
{
int n,i;
scanf("%d", &n);
int A[n];
for(i=0;i<n;i++)
    scanf("%d", &A[i]);
bubble_sort(A,n);
for(i=0;i<n;i++)
    printf("%d ", A[i]);
return 0;

}
