class Solution {
public:
    vector<vector<string>> ans;

    // checks if placing a queen at (row, col) is safe given queens
    // already placed in rows above (0..row-1)
    // only need to check column + both upper diagonals,
    // since rows below current row are still empty
    bool isSafe(vector<vector<char>> &board, int row, int col, int n) {

        // check same column, going upward
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true; // no conflicts -> safe to place queen here
    }

    // tries to place one queen per row, row by row (0 to n-1)
    void solve(vector<vector<char>> &board, int row, int n) {

        // base case: placed a queen in every row -> valid full board found
        if (row == n) {
            vector<string> temp;
            string t = "";
            // convert char grid into vector<string> for this solution
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    t += board[i][j];
                }
                temp.push_back(t);
                t = "";
            }
            ans.push_back(temp);
            return;
        }

        // try placing queen in each column of the current row
        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';       // place queen

                solve(board, row + 1, n);    // recurse to next row

                board[row][col] = '.';       // backtrack: undo placement, try next col
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        // n x n board, all cells initially empty ('.')
        vector<vector<char>> board(n, vector<char>(n, '.'));
        solve(board, 0, n);
        return ans;
    }
};