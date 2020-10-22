#include<stdio.h>
int main()
{
    int n, arr[10000], key = 0, i, found = 0;
    printf("Enter Size of Array\n");
    scanf("%d", &n);
    printf("Enter Array elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter Key to Search\n");
    scanf("%d", &key);
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            found = 1;
            printf("found at position %d", i + 1);
        }
    }
    if (found == 0)
        printf("Not Found\n");

    return 0;
}
