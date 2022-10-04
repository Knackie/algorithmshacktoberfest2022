/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> result;
    	if(!root)
    	return result;
    	
    	queue<Node*> nodesQueue;
    	nodesQueue.push(root);
    	
    	int leftToRight = 0;
    	while(!nodesQueue.empty()){
    	    int size = nodesQueue.size();
    	    vector<int> row;
    	    for(int i=0; i<size; i++){
    	        Node* node = nodesQueue.front();
    	        nodesQueue.pop();
    	        
    	        row.push_back(node->data);
    	        
    	        if(node->left)
    	        nodesQueue.push(node->left);
    	        if(node->right)
    	        nodesQueue.push(node->right);
    	    }
    	    
    	    if(leftToRight%2 != 0){
    	        reverse(row.begin(),row.end());
    	    }
    	    leftToRight++;
    	    for(int i=0; i<row.size(); i++){
    	        result.push_back(row[i]);
    	    }
    	}
    	return result;
    	
    	
    }
};
