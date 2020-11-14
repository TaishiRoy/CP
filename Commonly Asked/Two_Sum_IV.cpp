
// Two Sum IV - Input is a BST
// Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.
// more at https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// O(n) time complexity O(n) auxiliary space

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
    bool find(TreeNode* root, int k, unordered_set<int>& st)
    {
        if(!root)   return false;
        
        if(st.count(k-root->val)) return true;
        st.insert(root->val);
        return (find(root->left, k, st) || find(root->right, k, st));
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        return find(root, k, st);
    }
};
