# include<stdio.h>

float t_profit=0, x[50];
 
void display( int n)
{
 int i;
   printf("\nThe result vector is:- ");
   for (i = 0; i < n; i++)
      printf("%f\t", x[i]);
 
   printf("\nMaximum profit is:- %f", t_profit);

}

void sort_Descending(int n, float weight[], float profit[], float ratio[])
{
 int i, j, temp;
 //sort
   for (i = 0; i < n; i++) 
   {
      for (j = i + 1; j < n; j++) 
	{
         if (ratio[i] < ratio[j]) 
	  {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;
 
            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;
 
            temp = profit[j];
            profit[j] = profit[i];
            profit[i] = temp;
         }
       }
     }
} 

void Greedy_fract_knapsack(int n, float weight[], float profit[], float capacity)
 {
   int i, j, u;
   float ratio[20];
   u = capacity;
 
   for (i = 0; i < n; i++) // solution vector initialization
      x[i] = 0.0;
      
   for (i = 0; i < n; i++) 
      ratio[i] = profit[i] / weight[i];
      
   sort_Descending(n, weight, profit, ratio);
   
   for (i = 0; i < n; i++) 
   {
      if (weight[i] > u)
         break;
      else 
	  {
         x[i] = 1.0;
         t_profit = t_profit + profit[i];
         u = u - weight[i];
      }
   }
 
   if (i < n)
    {
      x[i] = u / weight[i];
      t_profit = t_profit + (x[i] * profit[i]);
    }
   display(n);     
}//end Greedy_fract_knapsack()

int main()
{
   float weight[20], profit[20], capacity;
   int num, i;
 
   printf("\nEnter the no. of items:- ");
   scanf("%d", &num);
 
   printf("\nEnter the weights and profits of each item:- ");
   for (i = 0; i < num; i++) 
      scanf("%f %f", &weight[i], &profit[i]);
 
   printf("\nEnter the capacity of knapsack:- ");
   scanf("%f", &capacity);
 
   Greedy_fract_knapsack(num, weight, profit, capacity); 
  return(0);
}//end main
