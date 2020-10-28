

// Path to Given Node
// Given a Binary Tree A containing N nodes.
// You need to find the path from Root to a given node B.
// more at https://www.interviewbit.com/problems/path-to-given-node/

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
 
bool util(vector<int> &path, TreeNode* A, int B)
{
    if(A==NULL) return false;
    if(A->val==B)
    {
        path.push_back(A->val);
        return true;
    }
    
    if(util(path, A->left, B) || util(path, A->right, B))
    {
        path.push_back(A->val);
        return true;
    }
    return false;
    
    
}

 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> path;
    bool found=util(path, A, B);
    reverse(path.begin(), path.end());
    return path;
}
