

// Min Depth of Binary Tree

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
class Solution {
public:
    int minDepth(TreeNode* A) {
        if(!A)  return 0;
        if(!A->left && !A->right)  return 1;
        return min(A->left ? minDepth(A->left) : INT_MAX, A->right ? minDepth(A->right) : INT_MAX)+1;

    }
};

