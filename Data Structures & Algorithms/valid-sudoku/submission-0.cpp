class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int rows = 0; rows < 9 ; rows ++){
            unordered_set<char> seen;
            for(int i=0; i < 9 ; i++){
                char ch  = board[rows][i];
                if(ch == '.') continue;

                if(seen.count(ch)) return false;
                seen.insert(ch);
            }
        }

        for(int col = 0; col < 9; col++){
            unordered_set<char> seen;
            for(int i =0; i<9; i++){
                char ch = board[i][col];
                if(ch == '.') continue ;
                if(seen.count(ch)) return false;
                seen.insert(ch); 
            }
        }

        for(int square = 0 ; square < 9; square++){
            unordered_set<char> seen;
            for(int i=0; i<3; i++ ){
                for(int j=0; j<3; j++){
                    int row = (square / 3) *3 + i;
                    int col = (square % 3) *3 + j;
                    if (board[row][col] == '.') continue;
                    if (seen.count(board[row][col])) return false;
                    seen.insert(board[row][col]);
                }
            }
        }


        return true;
    }
};