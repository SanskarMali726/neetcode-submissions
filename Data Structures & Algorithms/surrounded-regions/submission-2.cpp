class Solution {
public:
    int n, m;
    vector<vector<int>> vis;

    bool validregion(
        int r,
        int c,
        vector<vector<char>>& board,
        vector<pair<int,int>>& region
    ) {
        vis[r][c] = 1;
        region.push_back({r, c});

        bool surrounded = true;

        if (r == 0 || r == n - 1 || c == 0 || c == m - 1) {
            surrounded = false;
        }

        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < m &&
                board[nr][nc] == 'O' &&
                !vis[nr][nc]) {

                if (!validregion(nr, nc, board, region)) {
                    surrounded = false;
                }
            }
        }

        return surrounded;
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        vis.assign(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == 'O' && !vis[i][j]) {

                    vector<pair<int,int>> region;

                    bool surrounded =
                        validregion(i, j, board, region);

                    if (surrounded) {
                        for (auto [r, c] : region) {
                            board[r][c] = 'X';
                        }
                    }
                }
            }
        }
    }
};