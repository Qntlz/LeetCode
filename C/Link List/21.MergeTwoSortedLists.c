#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* a, struct ListNode* b) {
    struct ListNode* result = NULL;

    // Base Cases
    if(a == NULL) return b;
    else if(b == NULL) return a;

    if(a->val <= b->val)
    {
        result = a;
        result->next = mergeTwoLists(a->next,b);
    }
    else
    {
        result = b;
        result->next = mergeTwoLists(a,b->next);
    }
    return result;  
}
