class Solution {
public:
    class Node{
        public:
            char letter;
            Node* children[26];
            bool isTerminal;
            int index;

            Node(char c){
                letter = c;
                for(int i=0;i<26;i++){
                    children[i] = NULL;
                }
                isTerminal = false;
                index = -1;
            }
    };

    Node* root = new Node('0');

    void insertUtil(Node* r , string word,int i){
        if(word.length() == 0){
            r->isTerminal = true;
            r->index = i;
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

        return insertUtil(child,word.substr(1),i);
    }

    void insert(string word,int i) {
        insertUtil(root,word,i);
    }

    vector<vector<char>> board;
    int row, col;
    vector<string> ans;
    vector<string> words;

    void dfs(int r, int c, Node* root) {

        if (r < 0 || c < 0 || r >= row || c >= col || board[r][c] == '#') {
            return;
        }

        int index = board[r][c] - 'a';

        if (root->children[index] == NULL) {
            return;
        }

        Node* child = root->children[index];

        if (child->isTerminal) {
            ans.push_back(words[child->index]);
            child->isTerminal = false;
        }

        char original = board[r][c];
        board[r][c] = '#';

        dfs(r + 1, c, child);
        dfs(r - 1, c, child);
        dfs(r, c + 1, child);
        dfs(r, c - 1, child);
        
        board[r][c] = original;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        this->words = words;
        this->board = board;

        row = board.size();
        col = board[0].size();

        for(int i = 0; i < words.size(); i++){
            insert(words[i],i);
        }

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                dfs(r, c,root);
            }
        }

        return ans;
    }
};


//  this->board = board;
//         row = board.size();
//         col = board[0].size();
//         for(auto word : words){
//             if(exist(word)){
//                 ans.push_back(word);
//             }
//         }
//         return ans;



//     bool dfs(int r, int c, int i,string word) {
//         if (i == word.size()) {
//             return true;
//         }

//         if (r < 0 || c < 0 || r >= row || c >= col ||
//             board[r][c] != word[i]) {
//             return false;
//         }

//         char original = board[r][c];
//         board[r][c] = '#';

//         bool result = dfs(r + 1, c, i + 1,word) ||
//                       dfs(r, c + 1, i + 1,word) ||
//                       dfs(r - 1, c, i + 1,word) ||
//                       dfs(r, c - 1, i + 1,word);

//         board[r][c] = original;

//         return result;
//     }

//     bool exist(string word) {
//         for (int r = 0; r < row; r++) {
//             for (int c = 0; c < col; c++) {
//                 if (dfs(r, c, 0,word)) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }