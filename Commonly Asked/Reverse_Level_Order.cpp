
// function to get reverse level order traversal of a binary tree
// O(n) time complexity O(width) auxiliary space

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<int> Solution::solve(TreeNode* A) {
    vector<int> res;
    queue<TreeNode*> q;
    vector<int> curr;
    q.push(A);
    while(!q.empty())
    {
        int s = q.size();
        while(s--)
        {
            TreeNode* top = q.front();
            curr.push_back(top->val);
            if(top->left)   q.push(top->left);
            if(top->right)  q.push(top->right);
            q.pop();
        }
        res.insert(res.begin(), curr.begin(), curr.end());
        curr.clear();
    }
    return res;
}

