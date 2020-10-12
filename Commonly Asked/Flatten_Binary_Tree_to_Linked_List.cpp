
// function to Flatten Binary Tree to Linked List
// more at https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/
// O(n) time complexity


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void util(TreeNode* A, TreeNode* &prev)
{
    if(!A)  return;
    TreeNode* l=A->left;
    TreeNode* r=A->right;
    
    if(A!=prev)
    {
        prev->right=A;
        prev->left=nullptr;
        prev=A;
    }
    
    util(l, prev);
    util(r, prev);
}
 

TreeNode* Solution::flatten(TreeNode* A) {

    TreeNode* prev=A;
    util(A, prev);
    return A;
    
}


