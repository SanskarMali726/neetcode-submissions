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
    bool isValidBST(TreeNode* root) {
        //in this problem we are defining bound and we are checking that the new come node is within the bound or not if not return false this is the main logic 
        return helper(root,INT_MIN,INT_MAX);
    }
private:
    bool helper(TreeNode* root, int low,int upper){
        if(root == nullptr) return true;

        if(root->val >= upper || root->val <= low) return false;

        return helper(root->left,low,root->val) && helper(root->right,root->val,upper);

    }
};
