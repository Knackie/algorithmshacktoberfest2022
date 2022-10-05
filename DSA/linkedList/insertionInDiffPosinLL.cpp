#include<bits/stdc++.h>
using namespace std;

//------personal macro decelaration------
#define ll long long 
#define tc ll t=1;cin>>t;while(t--)
#define pi 3.14159265358979323846
//------code begin from here------

class Node{
    public :
        int data; //LinkedList elements
        Node *next;// pointer to next element

        //Creation of a node (Constructor)
        Node(int data){
            this->data=data;
            this->next = NULL;
        }

        //Deletion Of Node (Destructor)
        ~Node(){
            int val = this->data;
            if(this->next!=NULL){
                delete next;
                this->next = NULL;
            }
            cout << "Memory is free with data " << val<< endl;
        }
};

//Inserting Element at the beginnig
void insertAtHead(Node* &head,int d){
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
//Inserting at the end
void insertAtTail(Node* &tail,int d){
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
//Inserting AnyWhere
void insertInBetween(Node *&tail,Node *&head, int pos,int d)
{
    if(pos==1){
        insertAtHead(head, d);
        return;
    }
    
    Node *temp = head;
    int cnt = 1;
    while(cnt<pos-1){
        temp = temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertAtTail(tail, d);
        return;
    }
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// Deletion of a Node
void deleteNode(int pos,Node*&head, Node *&tail){
    if(pos==1){
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1; 
        while(cnt<pos){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if(curr->next==NULL){
            prev->next = curr->next;
            tail = prev;
        }
        else
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

//Traversing over Nodes (to print here)
void print(Node* &head){
    Node *temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node* rotateOnce(Node *head)
{
    Node *prev = NULL, *curr = head;
    while (curr->next != nullptr)
    {
        prev = curr;
        curr = curr->next;
    }
    curr->next = head;
    prev->next = nullptr;//true
    // *head = *curr;
    return curr;
}
int main()
{
  ios::sync_with_stdio(false); 
  cin.tie(NULL);
  Node *node1 = new Node(10);

  
  Node *head = node1;
  Node *tail = node1;
//   print(head);
  insertAtHead(head, 2);
//   print(head);
  insertAtTail(tail, 12);
  insertAtTail(tail, 25);
  print(head);
  head=rotateOnce(head);
  print(head);
  //   insertInBetween(tail,head, 1, 22);
  //   print(head);
  //   insertInBetween(tail, head, 4, 7);
  //   print(head);
  //   insertInBetween(tail, head, 1, 90);
  //   print(head);
  //   deleteNode(6, head,tail);
  //   print(head);
  // cout <<"head Node "<<head->data << endl;
  // cout <<"tail "<< tail->data << endl;
  return 0;
}