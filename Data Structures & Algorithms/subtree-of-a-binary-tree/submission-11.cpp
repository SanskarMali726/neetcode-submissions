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
// vector<int> res;

// void inorder(TreeNode* root , vector<int>& res){
//     if(!root) return;
//     inorder(root->left,res);
//     res.push_back(root->val);
//     inorder(root->right,res);
// }

// vector<TreeNode*> find(TreeNode* root,TreeNode* subroot){
//     vector<TreeNode*> ans;
//     queue <TreeNode*> q;
//     q.push(root);
//     while(!q.empty()){
//         TreeNode* curr = q.front();
//         q.pop();
//         if(curr->val == subroot->val){
//             ans.push_back(curr);
//         }
//         if(curr->left){
//             q.push(curr->left);
//         }
//         if(curr->right){
//             q.push(curr->right);
//         }
//     }
    
//     return ans;
// }

// class Solution {
// public:
//     bool isSubtree(TreeNode* root, TreeNode* subRoot) {
//         res.clear();
//         inorder(subRoot,res);
//         vector<int> brr = res;
//         res.clear();
        
//         vector<TreeNode*> roots = find(root,subRoot);
//         for(const auto& r : roots){
//             inorder(r,res);
//             vector<int> arr = res;
//             res.clear();
//             if(arr == brr){
//                 return true;
//             }
//         }
        
//         return false;
//     }
// };

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


bool isSameTree(TreeNode* root,TreeNode* subroot){
    queue <TreeNode*> a;
    queue <TreeNode*> b;

    a.push(root);
    b.push(subroot);
    while(!a.empty() && !b.empty()){
        TreeNode* a_curr = a.front();
        TreeNode* b_curr = b.front();
        a.pop();
        b.pop();
        
        if(!a_curr && !b_curr) continue; // if both are null continue 
        if(!a_curr || !b_curr) return false; // if one is not null and other is null then return false as structure change
        if(a_curr->val != b_curr->val) return false; // if both dont have value same return false


        //else push the next nodes
        a.push(a_curr->left);
        a.push(a_curr->right);
        b.push(b_curr->left);
        b.push(b_curr->right);
    }
    
    return true;
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
        
        
        vector<TreeNode*> roots = find(root,subRoot);
       
        for(const auto& r : roots){
            if(isSameTree(r,subRoot)){
                return true;
            }
        }

        
        return false;
    }
};

