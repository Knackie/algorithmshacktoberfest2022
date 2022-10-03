// C program to print left view of Binary Tree
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left, *right;
};

// A utility function to create a new Binary Tree node
struct node* newNode(int item)
{
	struct node* temp
		= (struct node*)malloc(sizeof(struct node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

// Recursive function to print left view of a binary tree.
void leftViewUtil(struct node* root, int level,
				int* max_level)
{
	// Base Case
	if (root == NULL)
		return;

	// If this is the first node of its level
	if (*max_level < level) {
		printf("%d\t", root->data);
		*max_level = level;
	}

	// Recur for left and right subtrees
	leftViewUtil(root->left, level + 1, max_level);
	leftViewUtil(root->right, level + 1, max_level);
}

// A wrapper over leftViewUtil()
void leftView(struct node* root)
{
	int max_level = 0;
	leftViewUtil(root, 1, &max_level);
}

// Driver code
int main()
{
	struct node* root = newNode(10);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(7);
	root->left->right = newNode(8);
	root->right->right = newNode(15);
	root->right->left = newNode(12);
	root->right->right->left = newNode(14);

	leftView(root);

	return 0;
}
