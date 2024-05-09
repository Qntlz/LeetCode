/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* highHead = NULL;
    struct ListNode* lowHead = NULL;
    struct ListNode* low = NULL;
    struct ListNode* high = NULL;
    struct ListNode* trav = head;

    if(head == NULL || head->next == NULL) return head;
    while(trav != NULL)
    {
        if(trav->val < x)
        {
            if(lowHead == NULL) lowHead = trav;
            else low->next = trav;
            low = trav;
        }
        else
        {
            if(highHead == NULL) highHead = trav;
            else high->next = trav;
            high = trav;
        }
        trav = trav->next;
    }
    if(lowHead != NULL && highHead != NULL)
    {
        high->next = NULL;
        low->next = highHead;
        return lowHead;
    }
    else if(lowHead == NULL)
    {
        high->next = NULL;
        return highHead;
    }
    low->next = NULL;
    return lowHead;
}