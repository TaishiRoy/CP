

// function to find Least Common Ancestor (nodes may or may not be present)
// O(n) time complexity O(h) auxiliary space



/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 bool util(vector<int> &vec, TreeNode* A, int key)
 {
     if(!A) return false;
    if(A->val==key)
    {
        vec.push_back(A->val);
        return true;
    }
    if(util(vec, A->left, key) || util(vec, A->right, key))
    {
        vec.push_back(A->val);
        return true;
    }
    return false;
 }
 
 
int lca(TreeNode* A, int B, int C) {
    vector<int> pathB, pathC;
    bool found1=util(pathB, A, B);
    bool found2=util(pathC, A, C);
    if(!found1 || !found2)  return -1;
    int len = min(pathB.size(), pathC.size());
    reverse(pathB.begin(), pathB.end());
    reverse(pathC.begin(), pathC.end());
    for(int i=0; i<len; i++)
    {
        if(pathB[i]!=pathC[i])  return pathB[i-1];
    }
    return pathB[len-1];
}

