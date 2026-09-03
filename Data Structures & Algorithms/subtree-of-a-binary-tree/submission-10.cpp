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
vector<int> res;

void inorder(TreeNode* root , vector<int>& res){
    if(!root) return;
    inorder(root->left,res);
    res.push_back(root->val);
    inorder(root->right,res);
}

vector<TreeNode*> find(TreeNode* root,TreeNode* subroot){
    vector<TreeNode*> ans;
    queue <TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        if(curr->val == subroot->val){
            ans.push_back(curr);
        }
        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }
    }
    
    return ans;
}

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        res.clear();
        inorder(subRoot,res);
        vector<int> brr = res;
        res.clear();
        
        vector<TreeNode*> roots = find(root,subRoot);
        for(const auto& r : roots){
            inorder(r,res);
            vector<int> arr = res;
            res.clear();
            if(arr == brr){
                return true;
            }
        }
        
        return false;
    }
};
