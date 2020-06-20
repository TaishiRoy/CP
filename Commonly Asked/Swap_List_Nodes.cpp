// function to swap two adjacent nodes in a linked list without modifying values of individual nodes
// O(n) time O(1) auxillary space

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
ListNode* swapPairs(ListNode* A) {
    if(A==NULL) return NULL;
    ListNode *head = A, *zeroth = A, *first = A;
    ListNode* second = first->next;
    if(second==NULL)    return head;
    ListNode *third = second->next;
    
    // handle the first two nodes
    first->next = NULL;
    second->next = first;
    first->next = third;
    head = second;
    if(first->next == NULL) return head;
    zeroth = first;
    first = first->next;
    second = first->next;
    third = second==NULL ? NULL : second->next;
    
    
    while(zeroth!=NULL && first!=NULL && second!=NULL)
    {
        // swap next two nodes
        first->next = NULL;
        second->next = first;
        if(third!=NULL)
            first->next = third;
        zeroth->next = second;
        zeroth = first;
        
        
        
        // reinitialize values of zeroth->first->second->third and continue;
        if(first->next!=NULL)
            first = first->next;
        else    
        {
            first = NULL;
            break;
        }
        
        if(first->next!=NULL)
            second = first->next;
        else    break;
        third = second==NULL ? NULL : second->next;
    }
    
    return head;
}
