// Find Largest Value in Each Tree Row
// more at https://leetcode.com/problems/find-largest-value-in-each-tree-row/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        
        vector<int> res;
        if(!root)   return res;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n=q.size();
            int curr=INT_MIN;
            while(n--)
            {
                TreeNode* top = q.front();
                curr = max(curr, top->val);
                q.pop();
                if(top->left)   q.push(top->left);
                if(top->right)  q.push(top->right);
            }
            res.push_back(curr);
        }
        
        return res;
        
    }
};
