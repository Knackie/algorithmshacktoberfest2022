// C Program for counting sort
#include <stdio.h>
#include <string.h>

int main()
{
	char arr[] = "countsort";
	char temp;
	int i,j;

for(i=0;arr[i]!='\0';i++)
{
for(j=0;j<strlen(arr)-1-i;j++)
{

	if(arr[j]>arr[j+1]){
       temp=arr[j];
       arr[j]=arr[j+1];
       arr[j+1]=temp;

	}
}
}

	printf("Sorted character array is = %s",arr);
	return 0;
}
