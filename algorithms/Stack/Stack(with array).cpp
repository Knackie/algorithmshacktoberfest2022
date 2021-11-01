#include<iostream>
using namespace std;
class stack {
	
public:
 
	int arr[5];
	int	stacktop  ;
 int maxsize;
 stack()
 {
 	stacktop=-1;
 	maxsize=10;
 	
 }
 
 stack(int max)
 {
 	stacktop=-1;
 	maxsize=max;
 }
	void isempty()
	{
		if (stacktop == -1)
		{
			cout << "\nStack is Empty\n";
		}

		else
		{
			cout << "\nStack isnt Empty\n";
		}
	};
	void isfull( )
	{
		if (stacktop == maxsize-1)
		{
			cout << "\nStack is Full\n";
		 }

		else
		{
			cout << "\nStack isnt full\n";
		}
	};
	int Pop()
	{
		if(stacktop==-1)
		{
			cout<<"Stack has no elements.";
			return -1;
		}
		else
		{
	    int s=stacktop;
		 stacktop = stacktop - 1;
		  return arr[s];
		 }

	};
	int Top()
	{   if(stacktop==-1)
		{
			cout<<"Stack has no elements.";
			return -1;
		}
		else
		return arr[stacktop];
	}
	void Push(int data)
	{
		if(stacktop==maxsize-1)
		{
			cout<<"Error:Overflow (no more elements can be added)";
			return;
		}
		else
		stacktop = stacktop + 1;
		arr[stacktop]=data;
		 
	};

	void print()
	{
		cout << endl<<"DATA : ";
		if(stacktop==-1)
		{
			cout<<" stack has no elements.";
			
		}
		else
		
		for (int i = 0; i <= stacktop; i++)
		{
			cout << arr[i] << ",";
		}
		cout << "\n\n\n";
	 }
};


int main()
{
	 
	cout<<"Enter the maxsize of stack: ";
	int ms;
	cin>>ms;
	stack s(ms);
	int o=-1;
	while (o != 0) {
	cout << "Select an option\n\t1 for *Push*\n\t2 for *Pop*\n\t3 for *Top*\n\t4 for *isempty*\n\t5 for *isfull*\n\t6 for *Print*\n\t0 for *Exit*\n";
	 cin >> o;
	 

	if (o == 1)
	{
		cout << "Enter data you want to enter : ";
		int d;
		cin >> d;
		s.Push(d);
	}
	else if (o == 2)
	{ 
	cout<<"Data : "<<s.Pop();
	}
	else if (o == 3)
	{

		cout << "Top Data : " << s.Top();

	}
	else if (o == 4)
	{

		s.isempty();

	}
	else if (o == 5)
	{

		s.isfull();

	}
	else if (o ==6)
	{

		s.print();

	}


	}
	return 0;
}
