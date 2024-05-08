/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* last = NULL;
    struct ListNode* temp = NULL;
    struct ListNode* prev = NULL;

    if(head == NULL || head->next == NULL) return head;      // Base Case

    while(fast != NULL)
    {
        if(fast->next == NULL)
        {
            last->next = fast;
            return head;
        }
        fast = fast->next;
        if(fast != NULL)
        {
            prev = fast;
            fast = fast->next;
            // Swap
            prev->next = slow;
            slow->next = fast;
            if(last == NULL) head = prev;
            else last->next = prev;
            last = slow;
            slow = fast;
            continue;
        }
    }
    return head;
}
