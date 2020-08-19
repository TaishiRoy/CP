
// function to create a deep copy of a given linked list with Random Node
// more at https://www.interviewbit.com/problems/copy-list/
// O(n) time complexity O(n) auxiliary space


/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* copyRandomList(RandomListNode* A) {
    unordered_map<RandomListNode*, RandomListNode*> mp;
    RandomListNode *head=A;
    while(A)
    {
        RandomListNode* newNode= new RandomListNode(A->label);
        mp[A]=newNode;
        A=A->next;
    }
    A=head;
    while(A)
    {
        mp[A]->next=mp[A->next];
        mp[A]->random=mp[A->random];
        A=A->next;
    }
    
    return mp[head];
}
