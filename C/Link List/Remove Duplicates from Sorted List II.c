/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* curr = head;
    struct ListNode* prev = NULL;

    // Empty or has only one element
    if(head == NULL || head->next == NULL) return head;

    // Check if the first two elements are duplicates
    if(head->val == head->next->val && head->next->next == NULL) return NULL;

    while(curr != NULL && curr->next != NULL) 
    {
        bool found = false;
        if(curr->val == curr->next->val) 
        {
            found = true;
            struct ListNode* fast = curr->next;
            while(fast != NULL && curr->val == fast->val) fast = fast->next;

            if(prev == NULL) head = fast;
            else prev->next = fast;
            curr = fast;
            continue;
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}
