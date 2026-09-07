class Solution {
public:
    int count = 0;
    vector<vector<int>> dp;

    bool solve(string &s,int i,int j){
        if(i >= j){
            return 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == s[j]){
            return dp[i][j] = solve(s,i+1,j-1);
        }
        else{
            return 0;
        }  
    }

    int countSubstrings(string s) {
        int n = s.size();
        this->dp.assign(n,vector<int>(n,-1));

        for(int i = 0;i < n; i++){
            for(int j = i; j < n; j++){
                if(solve(s,i,j)){
                    count++;
                }
            }
        }

        return count;
    }
};
