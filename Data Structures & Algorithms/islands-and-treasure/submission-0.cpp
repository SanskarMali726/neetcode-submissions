class Solution {
public:
    int n;
    int m;

    void bfs(vector<vector<int>>& grid,int path,int i,int j){
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};

        queue<pair<pair<int,int>,int>> q;
        q.push({{i,j},0});

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int path = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != -1 && grid[nr][nc] != 0){
                    if(path + 1 < grid[nr][nc]){
                        grid[nr][nc] = path + 1;
                        q.push({{nr,nc},grid[nr][nc]});
                    }  
                }
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if( grid[i][j] == 0){
                    bfs(grid,0,i,j);
                }
            }
        }
    }
};
