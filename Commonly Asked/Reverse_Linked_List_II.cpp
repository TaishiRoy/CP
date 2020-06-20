// function to reverse a linked list from position B to C (index starts from 1)
// O(n) time complexity an O(1) auxillary space

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
ListNode* reverseBetween(ListNode* A, int B, int C) {
    if(A==NULL) return NULL;
    C = C-B+1;    //distance from B to C
    ListNode *first = NULL;
    ListNode *second = A;
    ListNode *third = NULL;
    while(B>2)
    {
        second = second->next;        // move pointer to starting position of reverse process
        B--;
    }
    
    ListNode *left=NULL, *temp=second;
    if(B!=1)                         // B=1 indicates reversing starts from the beginning of list so there would be no previous node
    {
        left = second, temp = second->next;
        second = second->next;
    }
    
    while(second!=NULL && C>0)
    {
        third = second->next;     // iterative reversal
        second->next = first;
        first = second;
        second = third;
        C--;
    }
    
    temp->next = second;         // join the start and end of reversed segment to respective position of list
    if(B==1)    return first;
    left->next = first;
    
    return A;
}
