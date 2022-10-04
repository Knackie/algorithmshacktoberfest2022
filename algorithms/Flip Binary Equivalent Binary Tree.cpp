/*
Question: https://leetcode.com/problems/flip-equivalent-binary-trees/
Contributor: Mohit Radadiya

For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.
A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.
Given the roots of two binary trees root1 and root2, return true if the two trees are flip equivalent or false otherwise.
*/

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        //checking for leaf termination.
        if(root1 == NULL && root2 == NULL)
            return true;
        else if(root1 == NULL) return false;
        else if(root2 == NULL) return false;
        if(root1->val != root2->val)
            return false;
        if(root1->left == NULL && root1->right == NULL && root2->left == NULL && root2->right == NULL){
            return true;
        }
        bool check1, check2;
        if(root1->left && root2->left && root1->right && root2->right && root1->left->val == root2->left->val){
            check1 = flipEquiv(root1->left, root2->left);
            check2 = flipEquiv(root1->right, root2->right);
        }
        else if(root1->left && root2->left && root1->right && root2->right && root1->left->val == root2->right->val){
            check1 = flipEquiv(root1->left, root2->right);
            check2 = flipEquiv(root1->right, root2->left);
        }else if((root1->left && root2->left)|| (root1->right && root2->right)){
            check1 = flipEquiv(root1->left, root2->left);
            check2 = flipEquiv(root1->right, root2->right);
        }else if((root1->left && root2->right)|| (root1->right && root2->left)){
            check1 = flipEquiv(root1->left, root2->right);
            check2 = flipEquiv(root1->right, root2->left);
        }else{
            return false;
        }
        
        return check1 && check2;
    }
};
