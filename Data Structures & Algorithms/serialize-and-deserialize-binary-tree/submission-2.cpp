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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if(!root) return s;

        queue<TreeNode*> q;
        q.push(root);
 
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr == nullptr){
                s += "N/"; 
                continue;
            }

            s += to_string(curr->val);
            s += '/';

            if(curr->left){
                q.push(curr->left);
            }
            else q.push(nullptr);
            if(curr->right){
                q.push(curr->right);
            }
            else q.push(nullptr);
        
        }
        cout<<s<<endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> v;

        long long n = data.size();
        if(n == 0) return nullptr;

        long long i =0;

        string no = "";
        while(i < n){
            if(data[i] == '/' && no.size() > 0){
                int nu = stoi(no);
                TreeNode* temp = new TreeNode(nu);
                v.push_back(temp);
                no = "";
                
            }
            else if(data[i] == 'N'){
                v.push_back(nullptr);
                i++;
            }
            else{
                no += data[i];
            }
            i++;     
        }

        queue<TreeNode*> q;
        q.push(v[0]);
        int si = v.size();
        i = 1;
        TreeNode* root = v[0];
        while(i < si){
            TreeNode* t_root = q.front();
            q.pop();
    
            if(v[i]){
                t_root->left = v[i];
                q.push(v[i]);
                
            }
            i++;
            if(v[i]){
                t_root->right = v[i];
                q.push(v[i]);
            }
            i++;
        }
        
        return root;
    }
};
