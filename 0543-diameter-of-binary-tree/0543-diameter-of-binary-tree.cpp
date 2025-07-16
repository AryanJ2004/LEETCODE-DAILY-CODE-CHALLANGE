/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0;

        int lh=height(root->left);
        int rh=height(root->right);

        return max(lh,rh)+1;
    }

    int diameter(TreeNode *root){
        if(!root) return 0;
        int currDia=height(root->left)+height(root->right);

        int left=diameter(root->left);
        int right=diameter(root->right);
        return max({currDia,left,right});
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root);
    }
};