class Solution {
public:
    vector<vector<char>> board;
    string word;
    int row, col;

    // DFS: try to match word[i] starting from cell (r, c)
    bool dfs(int r, int c, int i) {

        // Entire word matched -> path is valid
        if (i == word.size()) {
            return true;
        }

        // Stop if:
        // 1. Out of bounds
        // 2. Current cell doesn't match word[i]
        // 3. Current cell was already used in this path
        if (r < 0 || c < 0 || r >= row || c >= col ||
            board[r][c] != word[i]) {
            return false;
        }

        // Mark current cell as visited so we don't use it again
        char original = board[r][c];
        board[r][c] = '#';

        // Try all 4 directions for the next character
        bool result = dfs(r + 1, c, i + 1) ||
                      dfs(r, c + 1, i + 1) ||
                      dfs(r - 1, c, i + 1) ||
                      dfs(r, c - 1, i + 1);

        // Backtrack: restore the cell for other possible paths
        board[r][c] = original;

        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        // Store board and word so dfs() can access them
        this->board = board;
        this->word = word;

        row = board.size();
        col = board[0].size();

        // Try starting the word from every cell
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {

                // If word can be formed from this cell, we're done
                if (dfs(r, c, 0)) {
                    return true;
                }
            }
        }

        // Word couldn't be formed from any starting cell
        return false;
    }
};