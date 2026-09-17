class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;

        unordered_map<Node*, Node*> m;
        queue<Node*> q;

        m[node] = new Node(node->val);
        q.push(node);

        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for(Node* x : curr->neighbors) {

                if(m.find(x) == m.end()) {
                    m[x] = new Node(x->val);
                    q.push(x);
                }

                m[curr]->neighbors.push_back(m[x]);
            }
        }

        return m[node];
    }
};