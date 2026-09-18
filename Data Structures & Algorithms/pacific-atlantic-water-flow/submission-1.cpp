class Solution {
public:
    int n;
    int m;
    vector<vector<int>> paci;
    vector<vector<int>> atl;

    bool reachPaci(int i,int j,vector<vector<int>>& heights){
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};

        vector<vector<int>> vis(n,vector<int>(m,0));

        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = 1;

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];


                if(nr < 0 || nc < 0){
                    return paci[r][c] = 1;
                }

                if(nr < n && nc < m && heights[nr][nc] <= heights[r][c] && vis[nr][nc] != 1){
                    if(paci[nr][nc] == 1){
                        return true;
                    }
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }


            }
        }

        return 0;
    }

    bool reachAtl(int i,int j,vector<vector<int>>& heights){
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};

        vector<vector<int>> vis(n,vector<int>(m,0));


        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = 1;

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr >= n || nc >= m){
                    return atl[r][c] = 1;
                }

                if(nr >= 0 && nc >=0 && heights[nr][nc] <= heights[r][c] && vis[nr][nc] != 1){
                    if(atl[nr][nc] == 1){
                        return 1;
                    }
                    q.push({nr,nc});
                    vis[nr][nc] = 1;
                }
            }
        }

        return 0;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        n = heights.size();
        m = heights[0].size();

        paci.assign(n,vector<int>(m,0));
        atl.assign(n,vector<int>(m,0));

        for(int i = 0;i < n; i++){
            for(int j = 0; j < m; j++){
                if(reachPaci(i,j,heights) && reachAtl(i,j,heights)){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};
