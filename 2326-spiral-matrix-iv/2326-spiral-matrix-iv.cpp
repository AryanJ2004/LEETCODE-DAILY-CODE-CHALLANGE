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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
          vector<vector<int>> mat(m,vector<int>(n,-1));
        
        int topRow=0, bottomRow=m-1, leftCol=0, rightCol=n-1;
        int i=0, j=0;
        while(head){
            // top row
            for(int col=leftCol; col<=rightCol; col++){
                if(!head) return mat;
                mat[topRow][col] = head->val;
                head = head->next;
            } ++topRow;

            // right col
            for(int row=topRow; row<=bottomRow; row++){
                if(!head) return mat;
                mat[row][rightCol] = head->val;
                head = head->next;
            } --rightCol;

            // bottom row
            for(int col=rightCol; col>=leftCol; col--){
                if(!head) return mat;
                mat[bottomRow][col] = head->val;
                head = head->next;
            } --bottomRow;

            // left col
            for(int row=bottomRow; row>=topRow; row--){
                if(!head) return mat;
                mat[row][leftCol] = head->val;
                head = head->next;
            } ++leftCol;
        }

        return mat;
    }
};