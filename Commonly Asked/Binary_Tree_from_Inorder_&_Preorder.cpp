
// function to construct Binary Tree from Inorder and Preorder 
// O(n^2) time complexity


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* util(vector<int> &A, vector<int> &B, int start, int stop, int &pre)
{
    if(start>stop) return NULL;
    TreeNode* root = new TreeNode(A[pre++]);
    int index=0;
    for(int i=start; i<=stop; i++)
    {
        if(B[i]==root->val)
        {
            index=i;
            break;
        }
    }
    root->left=util(A, B, start, index-1, pre);
    root->right=util(A, B, index+1, stop, pre);
    return root;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int pre=0;
    return util(A, B, 0, A.size()-1, pre);
}

