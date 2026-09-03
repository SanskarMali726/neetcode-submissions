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
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = inorder.size();
        int p = preorder.size();

        if(n == 0 || p == 0){
            return nullptr;
        }

        unordered_map<int,int> m;
        int i = 0;
        for(const auto& x : inorder){
            m[x] = i;
            i++;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        int mid = m[preorder[0]];

        vector<int> new_pre(preorder.begin()+1,preorder.begin()+mid+1);
        vector<int> new_ino(inorder.begin(),inorder.begin()+mid);
        root->left = buildTree(new_pre,new_ino);
        vector<int> pre(preorder.begin()+mid+1,preorder.end());
        vector<int> ino(inorder.begin()+mid+1,inorder.end());
        root->right = buildTree(pre,ino);
        
        return root;
    }
};
