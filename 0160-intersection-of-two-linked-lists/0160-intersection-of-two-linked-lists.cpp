class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;

        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while (t1 != t2) {
            t1 = t1 ? t1->next : headB;
            t2 = t2 ? t2->next : headA;
        }

        return t1;
    }
};
