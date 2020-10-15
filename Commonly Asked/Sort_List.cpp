

// Sort a linked list in O(n log n) time using constant space complexity.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* mergeList(ListNode* A,ListNode* B)
{
    if(!A)  return B;
    if(!B)  return A;
    
    if(A->val<B->val)
    {
        A->next = mergeList(A->next, B);
        return A;
    }
    else
    {
        B->next = mergeList(A, B->next);
        return B;
    }
    
}

 
 
ListNode* mergeSort(ListNode* A, int len)
{
    if(len<=1)  return A;
    int l=len/2;
    ListNode* B=A;
    while(l>1)
    {
        B=B->next;
        l--;
    }
    ListNode* prev = B;
    B=B->next;
    prev->next = NULL;
    ListNode* start = mergeSort(A, len/2);
    ListNode* end = mergeSort(B, len-(len/2));
    return mergeList(start, end);
}


ListNode* Solution::sortList(ListNode* A) {
    ListNode* head=A;
    int len=0;
    while(head)
    {
        head=head->next;
        len++;
    }
    return mergeSort(A, len);
}


/*     not using recursion stack

ListNode* mergeList(ListNode* A,ListNode* B)
{
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
*/
