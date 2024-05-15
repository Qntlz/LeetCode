/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) return NULL; // Base Case

    struct ListNode *fast = head;
    struct ListNode *slow = head;
    struct ListNode *entry = head; // entry point to the cycle

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) { // cycle detected
            while (slow != entry) { // find the entry point
                slow = slow->next;
                entry = entry->next;
            }
            return entry; // return the start of the cycle
        }
    }
    return NULL; // no cycle found
}
