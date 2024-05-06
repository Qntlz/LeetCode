/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* revList(struct ListNode* top, struct ListNode** last)
{
    struct ListNode* next = NULL;
    struct ListNode* prev = NULL;
    struct ListNode* curr = top;
    *last = top;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    int len = 0;
    struct ListNode* curr = head;
    struct ListNode* start = NULL;
    struct ListNode* next = NULL;
    struct ListNode* finalList = NULL;
    struct ListNode* tempList = NULL;
    struct ListNode* last = NULL;
    struct ListNode* prev = NULL;
    struct ListNode* trav = head;
    if(curr == NULL || curr->next == NULL) return curr;         // Base Case
    while(trav != NULL)
    {
        len++;
        trav = trav->next;
    }

    while (curr != NULL)
    {
        start = curr;
        if(len < k)
        {
            last->next = curr;
            return finalList;
        }
        for (int i = 0; i < k - 1 && curr->next != NULL; i++) curr = curr->next;
        next = curr->next;
        curr->next = NULL;
        prev = last;
        tempList = revList(start, &last);
        if(finalList == NULL) finalList = tempList;
        else prev->next = tempList;
        len-=k;
        curr = next;
    }
    return finalList;
}