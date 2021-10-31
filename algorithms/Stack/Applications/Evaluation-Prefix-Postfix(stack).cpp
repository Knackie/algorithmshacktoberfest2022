#include<iostream>
#include<stack>

using namespace std;

void Evaluation_of_Postfix(string x)
{
	stack<char> S;
	for (int i = 0; i <= (sizeof(x) - 1); i++)
	{
		int rr = x[i] + '0';
		if (isdigit(rr))
		{
			S.push(x[i]);
		}
		else if ((x[i] == '*') || (x[i] == '/') || (x[i] == '+') || (x[i] == '-'))
		{
			char c1 = S.top();
			int op2 = c1-'0';
			S.pop();
			char c2 = S.top();
			int op1 = c2-'0';

			int res;
			if (x[i] == '*')
			{
				res = op1*op2;
			}
			else if ((x[i] == '/'))
			{
				res = op1/op2;
			}
			else if ((x[i] == '+'))
			{
				res = op1+op2;
			}
			else if ((x[i] == '-'))
			{
				res = op1-op2;
			}

			char cc = res;
			S.push(cc);
		}
	}
	cout << "Answer = " << S.top();
}
void Evaluation_of_Prefix(string x)
{
	stack<char> S;
	for (int i = (sizeof(x) - 1); i >= 0; i--)
	{
		int rr = x[i] - '0';
		if (isdigit(rr))
		{ 
			S.push(x[i]);
		}
		else if ((x[i] == '*') || (x[i] == '/') || (x[i] == '+') || (x[i] == '-'))
		{
			char c1 = S.top();
			int op1 = c1 - '0';
			S.pop();
			char c2 = S.top();
			int op2 = c2 - '0';
			 

			int  res;
			if (x[i] == '*')
			{
				res = (op1)*(op2);
			}
			else if ((x[i] == '/'))
			{
				res = op1/op2;
			}
			else if ((x[i] == '+'))
			{
				res = op1+op2;
			}
			else if ((x[i] == '-'))
			{
				res = op1-op2;
			}

			char cc = res  ;
			S.push(cc);
		}
	}
	cout << "Answer = " << S.top();
}

int main()
{
	string x = "12+6-5*";
	Evaluation_of_Postfix(x);
	string h = "+1-4/64";
	Evaluation_of_Prefix(h);
	return 0;
}


