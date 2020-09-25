
// function to convert sorted list to Binary Search Tree (height balanced) given a singly linked list where elements are sorted in ascending order
// O(1) auxiliary space O(n) time complexity


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
TreeNode* util(ListNode* A, int len)
{
    
    if(len==0)  return NULL;
    if(!A)  return NULL;
    ListNode *mid=A, *end=A;
    int len2 = len;
    while(len2>1 && end && end->next)
    {
        end=end->next->next;
        mid=mid->next;
        len2-=2;
    }
    TreeNode* B=new TreeNode(mid->val);
    B->left = util(A, len/2);
    B->right = util(mid->next, len-1-(len/2));
    return B;
}

TreeNode* sortedListToBST(ListNode* A) {
    ListNode* head = A;
    int len=0;
    while(head)
    {
        head=head->next;
        len++;
    }
    return util(A, len);
}

