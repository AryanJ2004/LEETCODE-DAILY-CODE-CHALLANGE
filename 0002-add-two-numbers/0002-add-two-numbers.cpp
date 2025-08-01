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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dhead=new ListNode(0);
        ListNode* tail=dhead;
        int carry=0;

        while(l1!=NULL || l2!=NULL || carry!=0){
            int d1=(l1!=NULL) ? l1->val : 0;
            int d2=(l2!=NULL) ? l2->val : 0;

            int sum=d1+d2+carry;
            int digit=sum%10;
            carry=sum/10;

            ListNode *newNode= new ListNode(digit);
            tail->next=newNode;
            tail=tail->next;
            l1 = (l1 != nullptr) ? l1->next : NULL;
            l2 = (l2 != nullptr) ? l2->next : NULL;
        }
        ListNode *res=dhead->next;
        delete dhead;
        return res;
    }
};