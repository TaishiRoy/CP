
// function to find the maximum sum path in a binary tree 
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
 
int util(TreeNode* A, int &maxSum)
{
    if(!A)  return 0;
    int l= util(A->left, maxSum);
    int r= util(A->right, maxSum);
    int currMax = max(max(l,r)+A->val, A->val);
    maxSum = max(maxSum, max(A->val+l+r, currMax));
    return currMax;
    
}
 
int maxPathSum(TreeNode* A) {
    int maxSum=A? A->val : 0;
    util(A, maxSum);
    return maxSum;
}
