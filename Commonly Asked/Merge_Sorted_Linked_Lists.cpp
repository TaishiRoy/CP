
// function to merge two sorted linked lists into a new list
// O(m+n) time O(m+n) auxillary space


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
    if(A==NULL) return B;
    if(B==NULL) return A;
    ListNode* C = new ListNode(0);
    ListNode* head = C;
    while(A!=NULL || B!=NULL)
    {
        if(A==NULL )
        {
            C->next = B;
            C = C->next;
            B = B->next;
            continue;
        }
        if(B==NULL )
        {
            C->next = A;
            C = C->next;
            A = A->next;
            continue;
        }
        
        if(A->val >= B->val)
        {
            C->next = B;
            C = C->next;
            B = B->next;
            continue;
        }
        if( A->val < B->val)
        {
            C->next = A;
            C = C->next;
            A = A->next;
        }
    }
    return head->next;
}
