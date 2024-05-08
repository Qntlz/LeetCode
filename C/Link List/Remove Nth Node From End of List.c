/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* prev = NULL;

    if(head == NULL) return NULL;
    for(int i = 0; i < n; i++) {
        if(fast == NULL) return head;
        fast = fast->next;
    }

    while(fast != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }

    if(prev == NULL)
    {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    prev->next = slow->next;
    free(slow);
    return head;
}