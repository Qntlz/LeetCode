/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void MergeSort(struct ListNode** top);
void split(struct ListNode* curr, struct ListNode** front, struct ListNode** back);
struct ListNode* sortedMerge(struct ListNode* a, struct ListNode* b);

struct ListNode* makeNode(int num) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = num;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode* curr = NULL;
    struct ListNode* newList = NULL;
    struct ListNode* newNode = NULL;
    struct ListNode* prev = NULL;

    if (listsSize == 0) return NULL;

    for (int i = 0; i < listsSize; i++) {
        curr = lists[i];
        while (curr != NULL) {
            newNode = makeNode(curr->val);
            if (newList == NULL) newList = newNode;
            else prev->next = newNode;
            prev = newNode;
            curr = curr->next;
        }
    }

    MergeSort(&newList);
    return newList;
}

void MergeSort(struct ListNode** top) {
    struct ListNode* a = NULL;
    struct ListNode* b = NULL;
    struct ListNode* curr = *top;

    if (curr == NULL || curr->next == NULL) return;

    // Split
    split(curr, &a, &b);

    // Recursion
    MergeSort(&a);
    MergeSort(&b);

    // Merge
    *top = sortedMerge(a, b);
}

void split(struct ListNode* curr, struct ListNode** front, struct ListNode** back) {
    struct ListNode* fast = curr->next;
    struct ListNode* slow = curr;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
    }

    *front = curr;
    *back = slow->next;
    slow->next = NULL;
}

struct ListNode* sortedMerge(struct ListNode* a, struct ListNode* b) {
    struct ListNode* result = NULL;
    // Base Case
    if (a == NULL) return b;
    else if (b == NULL) return a;

    if (a->val <= b->val) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}