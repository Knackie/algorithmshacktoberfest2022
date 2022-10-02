#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node{
  int data;
  Node* left;
  Node* right;
};
//function to create node
Node* create(int x){
  Node* temp=(Node*)malloc(sizeof(Node));
  temp->data=x;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}
//function to find the bottom view
struct bottom{
       Node* temp;
       int hd;
   };
void bottomView(Node *root)
{
   bottom p;
   queue<bottom>q;
   map<int,int>m;
   map<int,int>::iterator it;
   p.temp=root;
   p.hd=0;
   q.push(p);
   while(!q.empty()){
       bottom pnode=q.front();q.pop();
       m[pnode.hd]=(pnode.temp)->data;
       if((pnode.temp)->left){
           bottom node;
           node.temp=(pnode.temp)->left;
           node.hd=(pnode.hd)-1;
           q.push(node);
       }
       if((pnode.temp)->right){
           bottom node;
           node.temp=(pnode.temp)->right;
           node.hd=(pnode.hd)+1;
           q.push(node);
       }
   }
   for(it=m.begin();it!=m.end();it++){
       cout<<it->second<<" ";
   }
}
int main(){
  Node* root=create(1);
  root->left=create(2);
  root->left->right=create(3);
  root->left->right->left=create(4);
  root->left->right->right=create(5);
  root->right=create(6);
  root->right->left=create(7);
  root->right->left->right=create(8);
  root->right->right=create(9);
    cout<<"bottom view of the given tree is: "<<endl;
    bottomView(root);
    return 0;
}
