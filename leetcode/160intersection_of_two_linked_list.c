/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 int getLengthListNode(struct ListNode *head) {
    struct ListNode *l = head;
    int count = 0;
    for (; l; l = l->next) { count++; }
    return count;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *lA = headA;
    struct ListNode *lB = headB;

    int lenA = getLengthListNode(headA);
    int lenB = getLengthListNode(headB);
    if (lenA > lenB) {
        for (int i = 0; i < lenA - lenB; i++) { lA = lA->next; } 
    } else if (lenA < lenB){
        for (int i = 0; i < lenB - lenA; i++) { lB = lB->next; } 
    }

    for (; lA; lA = lA->next, lB = lB->next) {
        if (lA == lB) { return lA; }
    }

    return NULL;
}