
// function to get maximum level sum of a binary tree
// more at https://www.interviewbit.com/problems/maximum-level-sum/
// O(n) time complexity O(width) auxuliary space


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::solve(TreeNode* A) {
    queue<TreeNode*> q;
    q.push(A);
    int res=0;
    while(!q.empty())
    {
        int n = q.size();
        int sum=0;
        for(int i=0; i<n; i++)
        {
            TreeNode* now = q.front();
            sum += now->val;
            if(now->left)  q.push(now->left);
            if(now->right) q.push(now->right);
            q.pop();
        }
        res=max(res, sum);
        // cout << res << endl;
    }
    return res;
}
