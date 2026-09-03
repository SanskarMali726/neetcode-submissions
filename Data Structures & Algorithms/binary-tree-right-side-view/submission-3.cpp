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
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<int> temp;
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    if (root == nullptr) {
        return ans;
    }

    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if (curr == nullptr) {
            ans.push_back(temp);
            temp.clear();
            if (!q.empty()) {
                q.push(nullptr);
            }
            continue;
        }

        temp.push_back(curr->val);
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }

    return ans;
}

class Solution {
   public:
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> temp = levelOrder(root);
        vector<int> ans;


        for(const auto& arr : temp){
            ans.push_back(arr.back());
        }

        return ans;
    }
};
