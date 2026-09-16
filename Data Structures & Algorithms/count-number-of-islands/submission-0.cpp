class Solution {
public:
    int n;
    int m;

    void bfs(vector<vector<char>>& grid,int i, int j){
        
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};

        queue<pair<int,int>> q;
        grid[i][j] = 0;
        q.push({i,j});

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];
                
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1'){
                    grid[nr][nc] = 0;
                    q.push({nr,nc});
                }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    bfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
