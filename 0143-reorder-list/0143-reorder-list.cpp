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

ListNode* splitatmid(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head;
    ListNode* prev=NULL;

    while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(prev!=NULL){
        prev->next=NULL;
    }
    return slow;
}

ListNode* reverse(ListNode* head){
    ListNode* prev=NULL;
    ListNode* curr=head;
    ListNode* next;

    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    return prev;
}

void printll(ListNode* head){
    vector<int>ans;
    while(head!=NULL){
        ans.push_back(head->val);
        head=head->next;
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
public:
    void reorderList(ListNode* head) {
        ListNode* rightHead=splitatmid(head);
        ListNode* rightHeadRev=reverse(rightHead);
    

    ListNode* left=head;
    ListNode* right=rightHeadRev;
    ListNode* tail=right;
    while(left!=NULL && right!=NULL){
        ListNode* nxtleft=left->next;
        ListNode* nxtright=right->next;

        left->next=right;
        right->next=nxtleft;
        tail=right;
        left=nxtleft;
        right=nxtright;
    }
    if(right!=NULL){
        tail->next=right;
    }

    printll(head);
    }
};