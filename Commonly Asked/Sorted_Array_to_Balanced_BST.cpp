
// function to create a balanced bst from a sorted array
// O(n) time complexity O(logn) auxiliary space

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 

TreeNode* util(const vector<int> &A, int start, int stop)
{
    if(start>stop)  return NULL;
    int rootPos=(start+stop)/2;
    TreeNode* root = new TreeNode(A[rootPos]);
    root->left=util(A, start, rootPos-1);
    root->right=util(A, rootPos+1, stop);
    return root;
    
}
 

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    TreeNode* res;
    return util(A, 0, A.size()-1);
}
