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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->val == temp->next->val) {
                // Skip the duplicate node
                ListNode* nnode=temp->next;
                temp->next = temp->next->next;
                delete nnode;
            } else {
                // Move to the next node if no duplicate
                temp = temp->next;
            }
        }
        return head;
    }
};
