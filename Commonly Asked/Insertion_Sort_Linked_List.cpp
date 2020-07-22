// function to implement insertion sort in a linked list
// O(n^2) time complexity O(1) auxillary space

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode *currEl = A, *checkEl = A;
    while(currEl != NULL)
    {
        checkEl = A;
        while(checkEl != currEl)
        {
            if(checkEl->val > currEl->val)
            {
                int temp = currEl->val;
                currEl->val = checkEl->val;
                checkEl->val = temp;
            }
            else
            {
                checkEl= checkEl->next;
            }
            
        }
        currEl= currEl->next;
    }
    
    return A;
}

