/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* revList(struct ListNode* head)
{
    struct ListNode* prev = NULL;
    struct ListNode* next = NULL;
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

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    bool first;
    struct ListNode* main = NULL;
    struct ListNode* next = NULL;
    struct ListNode* link = NULL;
    struct ListNode* prev = NULL; 
    struct ListNode* leftHead = NULL;
    struct ListNode* newHead = NULL;
    struct ListNode* trav = head;

    if(head == NULL || head->next == NULL) return head;
    else if(left == right ) return head;
    else if(head->next->next == NULL && right <= 2) return revList(head);

    first = false;
    for(int i = 0; trav != NULL; i++)
    {   
        if(newHead == NULL) newHead = trav;
        if(i == left - 1 && prev == NULL)
        {
            first = true;
            leftHead = trav;
        }
        else if(i == left - 1)
        {
            main = prev;
            leftHead = trav;
        }
        
        if(i == right - 1)
        {
            if(trav->next != NULL) next = trav->next;
            trav->next = NULL;
            break;
        }
        prev = trav;
        trav = trav->next;
    }
    link = leftHead;
    leftHead = revList(leftHead);
    link->next = next;
    if(first) return leftHead;
    main->next = leftHead;
    return newHead;
}