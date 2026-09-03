class WordDictionary {
public:
    class Node{
        public:
            char l;
            Node* children[26];
            bool isTerminal;

            Node(char s){
                l = s;
                for(int i = 0; i < 26; i++){
                    children[i] = NULL;
                }
                isTerminal = false;
            }
    };

    Node* root;
    
    WordDictionary() {
        root = new Node('0');
    }

    void addWordUtil(Node* root,string word){
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
       
        Node* child;
        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        //absent
        else{
            child = new Node(word[0]);
            root->children[index] = child;
        }

        addWordUtil(child,word.substr(1));
    }
    
    void addWord(string word) {
        addWordUtil(root,word);
    }

    bool searchUtil(Node* root,string word){
        if(word.size() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'a';
    

        Node* child;
        if(index < 0){
            for(Node* x : root->children){
                if(x != NULL){
                    if(searchUtil(x,word.substr(1))){
                        return true;
                    }
                }
            }
            return false;
        }
        //present
        else if(root->children[index] != NULL){
            child = root->children[index];
        }
        //absent
        else{
           return false;
        }

        return searchUtil(child,word.substr(1));

    }
    
    bool search(string word) {
        return searchUtil(root,word);
    }
};
