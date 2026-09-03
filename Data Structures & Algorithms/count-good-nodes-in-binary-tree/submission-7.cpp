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
    int goodNodes(TreeNode* root) {
        
        int count = 0;
        if(root == nullptr) return count;
        int max = INT_MIN;
        unordered_set<TreeNode*> se;
        stack<pair<TreeNode*,int>> s;
        pair<TreeNode*,int> start = {root,max};
        s.push(start);
        

        while(!s.empty()){
            TreeNode* curr = s.top().first;
            max = s.top().second;
            if(curr->left && !se.contains(curr->left)){
                if(max <= curr->val) max = curr->val; 
                pair<TreeNode*,int> temp = {curr->left,max};
                s.push(temp);
                se.insert(curr->left);
            }
            else if(curr->right && !se.contains(curr->right)){
                if(max <= curr->val) max = curr->val;
                pair<TreeNode*,int> temp = {curr->right,max};
                s.push(temp);
                se.insert(curr->right);   
            }
            else{
                if(curr->val >= max ) count++;
                s.pop();
            }
        }
        

        return count;
        
    } 
};
