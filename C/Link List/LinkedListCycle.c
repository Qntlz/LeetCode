/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    
    if(head == NULL || head->next == NULL) return NULL;
    struct ListNode* fast = head->next;
    struct ListNode* slow = head;
    
    while (fast != NULL && fast->next != NULL && slow != NULL) {
    if(slow == fast) return true;
    slow = slow->next;
    fast = fast->next->next;
}
    return false;   
}