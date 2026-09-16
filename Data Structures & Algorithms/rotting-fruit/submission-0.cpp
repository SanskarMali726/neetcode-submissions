class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int freshCount = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<pair<int,int>, int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else if(grid[i][j] == 1){
                    freshCount++;
                }
            }
        }

        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};

        int tm = 0;
        int count = 0;

        while(!q.empty()) {

            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            q.pop();

            tm = max(tm, t);

            for(int i = 0; i < 4; i++) {

                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m &&
                   vis[nr][nc] != 2 &&
                   grid[nr][nc] == 1) {

                    vis[nr][nc] = 2;
                    q.push({{nr, nc}, t + 1});
                    count++;
                }
            }
        }

        if(freshCount != count) {
            return -1;
        }

        return tm;
    }
};