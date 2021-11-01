#include<iostream>
#include<stack>

using namespace std;

bool Balancing_Paranthesis(char arr[], int size)
{
	
//make stack
stack<char> S;

//scanning from left to right
 for(int i=0; i<size;i++)
 {
 	if((arr[i]=='(') || (arr[i]=='{') || (arr[i]==')'))
 	{
 		//if(it is an open bracket enter it in stack)
 		S.push(arr[i]);
	 }
	 else if((arr[i]==')') || (arr[i]=='}') || (arr[i]==']'))
	 {
	 	if(S.empty()) 
		 {
		 	return false;
		  } 
		  //check if the top paranthesis of the stack is of the *same type* of this closing paranthesis
		  else if (arr[i]==')')
		  {
		  	if(S.top()=='(')
		  	{
		  		S.pop();
			  }
			  else
			  {
			  	return false;
			  }
		  }
		  
		   else if (arr[i]=='}')
		  {
		  	if(S.top()=='{')
		  	{
		  		S.pop();
			  }
			  
			   else
			  {
			  	return false;
			  }
		  }
		  
		   else if (arr[i]==']')
		  {
		  	if(S.top()=='[')
		  	{
		  		S.pop();
			  }
			  
			   else
			  {
			  	return false;
			  }
		  }
		  
	}
 	
 }
 //scaning completed
 
 if(S.empty())
{
	return true;
 } 
  else if(!S.empty())
{
	return false;
 } 
}
int main()
{
int size;
cout<<"Enter size of the array: ";
cin>>size;
char arr[10];
cout<<"valueNo: \n";
for(int i=0 ; i<size; i++)
{cout<<i+1<<"\t:";
cin>>arr[i];
    cout<<endl;
} 

if(Balancing_Paranthesis( arr , size))
{ cout<<"\n Paranthesis is balanced";

}
 
 else
 { cout<<"\n Paranthesis is notbalanced";
 
 }
	return 0;
}
