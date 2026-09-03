class Solution {
public:
    vector<vector<string>> ans;

    bool isSafe(vector<vector<char>> &board,int row,int col,int n){
        //is there any queen in same column 
        for(int i = row - 1; i >= 0; i--){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        //for upper left diagonal side
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--,j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        //for upper right diangonal side
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
            if (board[i][j] == 'Q'){
                return false;
            }
        }

        return true;
    }

    void solve(vector<vector<char>> &board,int row,int n){
        if(row == n){
            vector<string> temp;
            string t = "";
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    t += board[i][j];
                }
                temp.push_back(t);
                t = "";
            }
            ans.push_back(temp);
            return;
        }

        for(int col = 0; col < n; col++){
            if(isSafe(board,row,col,n)){
                board[row][col] = 'Q';

                solve(board,row+1,n);

                board[row][col] = '.';
            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n,vector<char>(n,'.'));
        solve(board,0,n);
        return ans;
    }
};
