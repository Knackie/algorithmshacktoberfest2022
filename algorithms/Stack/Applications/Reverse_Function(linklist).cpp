#include<iostream>
#include<stack>
#include<stdlib.h>

using namespace std;

struct Node
{
	int data;
	struct Node* link;
};

void reverse_with_linklist(struct Node* head)
{
	stack<struct Node*> S;

	//first push the list in stack;
	struct Node* Now = head;
	while (Now != NULL)
	{
		S.push(Now);
		Now = Now->link;
	}

	//now reverse the linkedlist
	struct Node* nod = S.top();
	head = nod;
	S.pop();

	while (!S.empty())
	{
		nod->link = S.top();
		S.pop();
		nod = nod->link;
	}
	nod->link = NULL;

	//Now print the link list

	struct Node* point = head;
	while (point != NULL)
	{
		cout << " " << point->data;
		point = point->link;
	}

}
int main()
{

	struct Node* hed = (struct Node*)malloc(sizeof(struct Node));
	hed->data = 1;
	hed->link = NULL;

	//second node
	struct Node* curent = (struct Node*)malloc(sizeof(struct Node));
	curent->data = 2;
	curent->link = NULL;
	hed->link = curent;

	//third node
	curent = (struct Node*)malloc(sizeof(struct Node));
	curent->data = 3;
	curent->link = NULL;
	hed->link->link = curent;

	reverse_with_linklist(hed);
	return 0;
}
