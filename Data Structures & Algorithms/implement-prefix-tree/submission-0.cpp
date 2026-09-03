class PrefixTree {
public:

    class Node{
        public:
            char letter;
            Node* children[26];
            bool isTerminal;


            Node(char c){
                letter = c;
                for(int i=0;i<26;i++){
                    children[i] = NULL;
                }
                isTerminal = false;
            }
    };

    PrefixTree() {
    }
    Node* root = new Node('0');

    void insertUtil(Node* r , string word){
        if(word.length() == 0){
            r->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        Node* child;
        //present
        if(r->children[index] != NULL){
            child = r->children[index];
        }
        else{
        // absent
            child = new Node(word[0]);
            r->children[index] = child;
        }

        return insertUtil(child,word.substr(1));
    }

    void insert(string word) {
        insertUtil(root,word);
    }

    bool searchUtil(Node* root,string word){
        if(word.size() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        Node* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return false;
        }

        return searchUtil(child,word.substr(1));

    }
    
    bool search(string word) {
        return searchUtil(root,word);
    }

    bool startsWithUtil(Node* r,string prefix){
        if(prefix.length() == 0){
            return true;
        }

        int index = prefix[0] - 'a';
        Node* child;
        if(r->children[index] != NULL){
            child = r->children[index];
        }
        else{
            return false;
        }

        return startsWithUtil(child,prefix.substr(1));

    }
    
    bool startsWith(string prefix) {
        
        return startsWithUtil(root,prefix);
    }
};
