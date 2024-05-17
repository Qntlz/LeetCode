/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void split(struct ListNode* top,struct ListNode** first, struct ListNode** sec){
    struct ListNode* fast = top->next;
    struct ListNode* slow = top;
    while(fast)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    *first = top;
    *sec = slow->next;
    slow->next = NULL;
}

struct ListNode* sortedMerge(struct ListNode* a,struct ListNode* b){
    struct ListNode* result = NULL;

    if(a == NULL) return b;
    else if(b == NULL) return a;

    if(a->val <= b->val)
    {
        result = a;
        result->next = sortedMerge(a->next,b);
    }
    else
    {
        result = b;
        result->next = sortedMerge(a,b->next);
    }
    return result;
}

void MergeSort(struct ListNode** top){
    struct ListNode* a = NULL;
    struct ListNode* b = NULL;
    struct ListNode* curr = *top;
    
    if (curr == NULL || curr->next == NULL) return;

    // Split
    split(curr,&a,&b);

    // Sort
    MergeSort(&a);
    MergeSort(&b);

    //Merge
    *top = sortedMerge(a,b);
}

struct ListNode* sortList(struct ListNode* head) {
    MergeSort(& head);
    return head;
}