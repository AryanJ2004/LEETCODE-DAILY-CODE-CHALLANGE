/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *md=head->next;
        ListNode *ns=md;
        while(ns!=NULL)
        {
            int sum=0;
            while(ns->val!=0)
            {
                sum+=ns->val;
                ns=ns->next;
            }
            md->val=sum;
            ns=ns->next;
            md->next=ns;
            md=md->next;
        }
        return head->next;
    }
};