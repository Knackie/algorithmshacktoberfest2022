#include<bits/stdc++.h>
using namespace std;

// Top view of binary seach tree
void topView(Node* head){
    if(head == NULL){
        return;
    }
    queue<pair<Node*, int>> q;
    map<int, int> m;
    q.push({head, 0});
    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n; i++){
            auto x = q.front();
            q.pop();
            if(m[x.second] == NULL){
                m[x.second] = x.first -> data;
            }
            if(x.first -> left != NULL){
                q.push({x.first -> left, x.second-1});
            }
            if(x.first -> second != NULL){
                q.push({x.first -> right, x.second+1});
            }
        }
    }
    for(auto i : m){
        cout << i.second << " ";
    }
}

int main(){
    Node* head = NULL;

    Node* head2 = insert(head, 10);
    Node* head3 = insert(head2, 20);
    Node* head4 = insert(head3, 30);
    Node* head5 = insert(head4, 40);
    Node* head6 = insert(head5, 50);
    
    topView(head6);

    return 0;
}