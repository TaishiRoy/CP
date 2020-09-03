// function to find the kth smallest element in a given binary search tree
// O(n) time complexity O(height) auxiliary space



/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* util(TreeNode* A, int &B)
{
    if(!A)  return NULL;
    TreeNode* a = util(A->left, B);
    B--;
    if(B==0)   return A;
    TreeNode* b = util(A->right, B);
    return a?a:b;
}

int Solution::kthsmallest(TreeNode* A, int B) {
    return util(A, B)->val;
}
