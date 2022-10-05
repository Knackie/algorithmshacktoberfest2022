#include<stdio.h>
#define ROW 10
#define COL 10

void ReadArray(int [ROW][COL], int, int);
void FindArray(int [ROW][COL], int, int,int);

main()
{
int r,c,sum,k;
int a[ROW][COL];
double avg;
printf("Enter the order of 2D matrix: ");
scanf("%d%d",&r,&c);
printf("\nEnter the Elements of Matix:\n");
ReadArray(a,r,c);


printf("\nEnter The Element to search: ");
scanf("%d",&k);
FindArray(a,r,c,k);
}

void ReadArray(int a[ROW][COL], int r, int c)
{
int i,j;
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
scanf("%d",&a[i][j]);
}
}
}

void FindArray(int a[ROW][COL], int r, int c,int k)
{
int i,j;
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
if(k==a[i][j]);
printf("\n Matched");
exit(0);
}
}
printf("\n UnMatched");
}
