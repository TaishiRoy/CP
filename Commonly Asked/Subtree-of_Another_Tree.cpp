
// function to find if a given tree is a subtree of the other tree
// more at https://leetcode.com/problems/subtree-of-another-tree/
// O(mn) time complexity

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
    
    bool isIdentical(TreeNode* a, TreeNode* b)
    {
        if(!a && !b)    return true;
        if(a && b)
        {
            if(a->val != b->val)    return false;
            return isIdentical(a->left, b->left) && isIdentical(a->right, b->right);
        }
        return false;
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!t)  return true;
        if(!s)  return false;
        
        if(s->val==t->val)
        {
            if(isIdentical(s, t))   return true;
        }
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
