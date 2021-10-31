#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	struct node* link;
};

class stack{
	
	public:
		struct node* top= NULL;
		
		 void isEmpty()
		  {
		  	if(top==NULL)
			{
				cout<<"stack is empty";
				return;
			}
			else 
			{
			    cout<<"stack isnt empty";
				return;
			}
		  }
		  
		  
		void Push(int dat){
	 
			struct node* N=(struct node*)malloc(sizeof(struct node*));
           N->data=dat;
           N->link= top;
           top=N;
              
        	}
        	
			void Pop(){
				
			if(top==NULL)
			{
				cout<<"stack is empty";
				return;
			}
			else
			{
				struct node* N=NULL;
				N=top;
				top=top->link;
				free(N);
				N=NULL;
				
		  	}
		  }
		  
		  void Top()
		  {
		    
				 cout<<"The data of TOP : "<<top->data;
				 
		  }
		  
		  
		  void print()
	{
		cout << endl<<"DATA : ";
		if(top==NULL)
		{
			cout<<" stack has no elements.";
			
		}
		else
		struct node* N=top;
		while(top!=NULL)
		{
			cout << top->data << ",";
			top=top->link;
		}
		cout << "\n\n\n";
		
	 }
		  	
};


int main()
{
	 
 
	stack s ;
	int o=-1;
	while (o != 0) {
	cout << "\nSelect an option\n\t1 for *Push*\n\t2 for *Pop*\n\t3 for *Top*\n\t4 for *isempty*\n\t5 for *Print*\n\t0 for *Exit*\n";
	 cin >> o;
 
	if (o == 1)
	{
		cout << "Enter data you want to enter : ";
		int d;
		cin >> d;
		s.Push(d);
	}
	else if (o == 2)
	{ s.Pop();
	cout<<"Data  removed";
	}
	else if (o == 3)
	{

	s.Top();

	}
	else if (o == 4)
	{

		s.isEmpty();

	}
 
	else if (o ==5)
	{

		s.print();

	}


	}
	return 0;
}
