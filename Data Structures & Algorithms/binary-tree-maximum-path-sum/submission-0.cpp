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
    // int getleft(TreeNode*root){
    //     if(!root->left) return 0;
    //     if(m.find(root->left) != m.end()){
    //         tuple<int,int,int> temp;
    //         temp = m[root->left];
    //         if(get<0>(temp) > get<2>(temp)) return get<0>(temp);
    //         else if(get<2>(temp) > get<0>(temp)) return get<2>(temp);
    //         else return get<0>(temp) + root->left->val;
    //     }
    //     return root->left->val + root->val;
    // }
    // int getright(TreeNode*root){
    //     if(!root->right) return 0;
    //     if(m.find(root->right) != m.end()){
    //         tuple<int,int,int> temp;
    //         temp = m[root->right];
    //         if(get<0>(temp) > get<2>(temp)) return get<0>(temp);
    //         else if(get<2>(temp) > get<0>(temp)) return get<2>(temp);
    //         else return get<0>(temp) + root->right->val;
    //     }
    //     return root->right->val + root->val;
    // }
    // int getmid(TreeNode*root){
    //     int mid = root->val;
    //     if(m.find(root->left) != m.end()){
    //         tuple<int,int,int> temp;
    //         temp = m[root->left];
    //         if(get<0>(temp) > get<2>(temp)) mid += get<0>(temp);
    //         else if(get<2>(temp) > get<0>(temp)) mid += get<2>(temp);
    //         else mid + get<0>(temp) + root->left->val;
    //     }
    //     else if(root->left) mid += root->left->val;

    //     if(m.find(root->right) != m.end()){
    //         tuple<int,int,int> temp;
    //         temp = m[root->right];
    //         if(get<0>(temp) > get<2>(temp)) mid += get<0>(temp);
    //         else if(get<2>(temp) > get<0>(temp)) mid += get<2>(temp);
    //         else mid + get<0>(temp) + root->right->val;
    //     }
    //     else if(root->right) mid += root->right->val;
    //     return mid;
    // }
    unordered_map<TreeNode*,pair<int,int>> m;
   
    int getUpper(TreeNode* root){
        int l = root->val;
        int r = root->val;
        if(m.find(root->left) != m.end()){
            pair<int,int> temp;
            temp = m[root->left];
            if(temp.first >= 0){
                l +=  temp.first;
            }
        }
        if(m.find(root->right) != m.end()){
            pair<int,int> temp;
            temp = m[root->right];
            if(temp.first >= 0){
                r += temp.first;
            }
        }

        return max(l,r);
    }

    int getBest(TreeNode* root){
        int l = 0;
        int r = 0;
        if(m.find(root->left) != m.end()){
            pair<int,int> temp;
            temp = m[root->left];
            if(temp.first >= 0){
                l = temp.first;
            }
        }
        
        if(m.find(root->right) != m.end()){
            pair<int,int> temp;
            temp = m[root->right];
            if(temp.first >= 0){
                r = temp.first;
            }
        }
        
        return l+r+root->val;
    }

    pair<int,int> helper(TreeNode* root){
        int upper = getUpper(root);
        int best = getBest(root);
        pair<int,int> temp = {upper,best};
        return temp;
    }


    int maxPathSum(TreeNode* root) {
        int maximum = INT_MIN;
        stack<TreeNode*> st;
        unordered_set<TreeNode*> v;

        st.push(root);

        while(!st.empty()){
            TreeNode* curr = st.top();
            if(curr->left && !v.contains(curr->left)){
                v.insert(curr->left);
                st.push(curr->left); 
            }
            else if(curr->right && !v.contains(curr->right)){
                v.insert(curr->right);
                st.push(curr->right);
            }
            else{
                pair<int,int> temp = helper(curr);
                m[curr] = temp;
                int t = max(temp.first,temp.second);
                maximum =(maximum < t) ? t : maximum;
                st.pop();
            }
            
        }
      
        return maximum;
    }
};
