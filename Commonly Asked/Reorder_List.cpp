
// function to reorder list : Given a singly linked list L: L0 → L1 → … → Ln-1 → Ln, reorder it to: L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
// more at https://www.interviewbit.com/problems/reorder-list/
// O(n) time complexity O(1) auxiliary space


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverse(ListNode* A)
{
    ListNode* prev=NULL, *curr = A, *next=A->next;
    while(curr)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

ListNode* Solution::reorderList(ListNode* A) {
    ListNode *slow=A, *fast=A;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* scnd= reverse(slow->next);
    slow->next = NULL;
    ListNode* frst= A;
    
    while(frst && scnd)
    {
        ListNode* frstcurr = frst, *scndcurr = scnd;
        scnd=scnd->next;
        frst=frst->next;
        frstcurr->next=scndcurr;
        scndcurr->next=frst;
    }
    
    return A;
}

