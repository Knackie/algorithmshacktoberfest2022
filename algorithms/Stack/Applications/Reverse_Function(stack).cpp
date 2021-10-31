 #include<iostream>
#include<stack>
using namespace std;

void reverse_with_array(char C[] ,int n)
{
	//putting all values in stack
	stack<char> S;
	for(int i=0; i<n; i++)
	{
		S.push(C[i]);
		
	}
	//all values are in stack now
	
	//now put the values of stack in array to reverse
	
	for(int i=0; i<=n; i++)
     {
	C[i]=S.top();
	S.pop();
	  }
	  
 	cout<<"Reverse of array : ";
	  //now print the array 
	  for(int i ; i<n ; i++)
	  {
	  	cout <<C[i];
	  }

}

int main()
{
   char Carr[4]={'A','B','c','D'};
	 
   reverse_with_array( Carr ,4);
  
  return 0;

}
 
