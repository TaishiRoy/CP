

// Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum. 
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
 
bool util(TreeNode* A, int sum, vector<int> curr, vector<vector<int>> &res)
{
    if(!A)  return false;
    if(sum==A->val && !A->left && !A->right)    
    {
        curr.push_back(A->val);
        res.push_back(curr);
        return true;
    }
    curr.push_back(A->val);
    bool l = util(A->left, sum-A->val, curr, res);
    bool r = util(A->right, sum-A->val, curr, res);
    return l||r;
}

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>> res;
    vector<int> curr;
    bool found = util(A, B, curr, res);
    return res;
}

