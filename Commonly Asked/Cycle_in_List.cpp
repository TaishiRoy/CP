
// function to detect cycle in a linked list and the starting node of loop
// O(n) time and O(1) auxillary space


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
ListNode* detectCycle(ListNode* A) {
    
    ListNode *slow=A, *fast=A;
    slow = A->next;
    fast = A->next->next;
    
    // to detect loop using Floyd's cycle detection algorithm
    while(slow != fast)
    {
        if(fast->next==NULL || fast->next->next==NULL)  return NULL;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // to find the starting node of loop
    slow = A;
    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
}
