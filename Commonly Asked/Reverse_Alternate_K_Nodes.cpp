// function to reverse alternate k nodes of linked list


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
 
 
ListNode* solve(ListNode* A, int B) {
    int count=0;
    ListNode* x=A;
    ListNode* head = reverseBetween(A, count+1, B);
    count+=B;
    int len=0;
    while(x!=NULL)
    {
        x=x->next;
        len++;
    }
    len++;
    while(count+B<len)
    {
        // cout << count << endl;
        count+=B;
        head = reverseBetween(head, count+1, B);
        count+=B;
    }
    
    return head;
}


