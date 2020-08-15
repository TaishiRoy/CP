
// function to rotate a list
// O(n) time complexity O(1) auxiliary space


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* Solution::rotateRight(ListNode* A, int B) {
    if(A==NULL || A->next==NULL)    return A;
    ListNode *rhead=A, *oend=A, *ohead=A, *rend=A;
    int len=1;
    while(A->next!=NULL)
    {
        A=A->next;
        len++;
    }
    oend=A;
    B=B%len;
    if(B==0)    return ohead;
    for(int i=1; i<(len-B); i++)
    {
        rend=rend->next;
    }
    rhead=rend->next;
    oend->next=ohead;
    rend->next=NULL;
    return rhead;
    
    
}

