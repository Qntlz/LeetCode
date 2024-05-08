/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    int ctr = 0;
    struct ListNode* trav = head;
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* tempHead = head;

    if(curr == NULL || curr->next == NULL) return head;     // Base Case

    while(curr != NULL)
    {
        ctr++;
        curr = curr->next;
    }
    for(int i = 0; i < (k % ctr); i++)
    {
        
        while(trav->next != NULL)
        {
            prev = trav;
            trav = trav->next;
        }
        prev->next = NULL;
        trav->next = tempHead;
        tempHead = trav;
    }
    return tempHead;
}