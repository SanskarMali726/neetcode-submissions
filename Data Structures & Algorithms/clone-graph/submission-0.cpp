/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        unordered_map<Node*,Node*> m;
        queue<Node*> q;
        Node* start = new Node(node->val);
        int count = 1;
        
        m[node] = start;
        q.push(node);
        

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            for(auto x : curr->neighbors){
                if(m.find(x) == m.end()){
                    m[x] = new Node(x->val);
                    q.push(x);
                    count++;
                } 
            }
        }

        vector<int> vis(count+1,0);
        q.push(node);
        vis[node->val] = 1;
        
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            for(auto x : curr->neighbors){
                m[curr]->neighbors.push_back(m[x]);
                if(vis[x->val] == 0){
                    q.push(x);
                    vis[x->val] = 1;
                }
            }
        }

        return start;
    }
};
