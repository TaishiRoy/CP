

// Add Two Numbers II problem
// more at https://leetcode.com/problems/add-two-numbers-ii/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int carry;
    
    ListNode* add(ListNode* a, ListNode* b)
    {
        if(!a->next && !b->next)
        {
            int curr = a->val+b->val+carry;
            carry = curr/10;
            a->val = curr%10;
            // cout << a->val << " ";
            return a;
        }
        ListNode* temp = add(a->next, b->next);
        int curr = a->val+b->val+carry;
        carry = curr/10;
        a->val = curr%10;
        return a;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = l1;
        int len1=0, len2=0;
        while(temp)
        {
            len1++;
            temp=temp->next;
        }
        temp=l2;
        while(temp)
        {
            len2++;
            temp=temp->next;
        }
        if(len1==len2)
        {
            l1 = add(l1, l2);
        }
        else if(len1>len2)
        {
            while(len1>len2)
            {
                ListNode* newHead = new ListNode();
                newHead->next = l2;
                l2=newHead;
                len2++;
            }
            l1 = add(l1, l2);
            
        }
        else 
        {
            while(len2>len1)
            {
                ListNode* newHead= new ListNode();
                newHead->next = l1;
                l1=newHead;
                len1++;
            }
            l1 = add(l1, l2);
        }
        if(carry>0)
        {
            ListNode* newHead = new ListNode(carry);
            newHead->next = l1;
            l1=newHead;
        }
        return l1;
    }
};
