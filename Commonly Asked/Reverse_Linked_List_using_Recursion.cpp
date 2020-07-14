// function to reverse a linked list using recursion
// O(n) time complexity O(n) auxillary space
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
void reverseUtil(ListNode* A, ListNode** B)
{
    if(A->next==NULL)
    {
        *B=A;
        return;
    }
    
    reverseUtil(A->next,B);
    ListNode* rev = A->next;
    rev->next = A;
    A->next = NULL;
    return;
}

ListNode* Solution::reverseList(ListNode* A) {
    ListNode* B=NULL;
    reverseUtil(A, &B);
    return B;
}
