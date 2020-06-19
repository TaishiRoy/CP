// function to get the intersection of two linked lists
// O(n) time and O(1) auxillary space

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode* headA = A, *headB = B;
    int lenA=0, lenB=0;
    
    // get length of two lists
    while(A != NULL)
    {
        lenA++;
        A= A->next;
    }
    
    while(B != NULL)
    {
        lenB++;
        B= B->next;
    }
    
    int diff = lenA > lenB ? lenA-lenB : lenB-lenA;
    ListNode *moveHead = lenA>lenB ? headA : headB;
    
    // place pointers to both lists where they are equidistant from the intersection point 
    for(int i=0; i<diff; i++ )
    {
        moveHead = moveHead->next;
    }
    
    if( lenA>lenB )
    {
        headA = moveHead;
    }
    else
        headB = moveHead;
    
    
    // keep incrementing the pointers until intersection is encountered
    while(headA != NULL || headB != NULL)
    {
        if(headA == headB)  return headA;
        headA = headA->next;
        headB = headB->next;
    }
    
    return NULL;
    
}

