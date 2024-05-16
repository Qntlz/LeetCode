/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode*  reverseList(struct ListNode* head)
{
    struct ListNode* next = NULL;
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void reorderList(struct ListNode* head) {
    if(!head || !head->next) return;
    struct ListNode* temp1 = NULL;
    struct ListNode* temp2 = NULL;
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* mainList = head;

    // Find the Half
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    // reverse half of the list
    struct ListNode* revList = reverseList(slow->next);
    slow->next = NULL;  // Cut the list

    // Merge List
    while(revList)
    {
        temp1 = mainList->next;
        temp2 = revList->next;

        mainList->next = revList;
        revList->next = temp1;

        mainList = temp1;
        revList = temp2;
    }
}