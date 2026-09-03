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
        if(root == NULL) return 0;

        int left_h = height(root->left);
        int right_h = height(root->right);

        return max(left_h,right_h)+1;
    }
 
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int left_d = diameterOfBinaryTree(root->left);
        int right_d = diameterOfBinaryTree(root->right);
        int curr_d = height(root->left) + height(root->right);

        return max(left_d,max(right_d,curr_d));
    }
};
