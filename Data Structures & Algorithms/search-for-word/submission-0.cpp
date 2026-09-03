class Solution {
public:
    vector<vector<char>> board;
    string word;
    int row, col;
    set<pair<int,int>> path;

    bool dfs(int r, int c, int i) {
        if (i == word.size()) {
            return true;
        }

        if (r < 0 || c < 0 || r >= row || c >= col ||
            board[r][c] != word[i] || path.contains({r,c})) {
            return false;
        }

        path.insert({r,c});

        bool result = dfs(r + 1, c, i + 1) ||
                      dfs(r, c + 1, i + 1) ||
                      dfs(r - 1, c, i + 1) ||
                      dfs(r, c - 1, i + 1);

        path.erase({r,c});

        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->word = word;

        row = board.size();
        col = board[0].size();

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (dfs(r, c, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};