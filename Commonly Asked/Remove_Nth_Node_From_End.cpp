// function to remove nth node from the end of linked list
// O(n) time complexity O(1) auxiliary space


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    if(B==1 && A->next==NULL)   return NULL;
    ListNode* thisNode =A, *head=A, *prevNode=A;
    B--;
    while(B--)
    {
        if(A->next==NULL)
        {
            return head->next;
        }
        A=A->next;
    }
    if(A->next==NULL)   
    {
        return head->next;
    }
    A=A->next;
    thisNode=thisNode->next;
    while(A->next!=NULL)
    {
        A=A->next;
        thisNode=thisNode->next;
        prevNode=prevNode->next;
    }
    prevNode->next=thisNode->next;
    return head;
}
