class Solution {
public:
    unordered_set<string> st;
    int n;

    bool solve(int i,string &s,vector<int> &dp){
        if(i >= n){
            return dp[i] = 1;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        if(st.contains(s)){
            return dp[i] = 1;
        }
        
        for(int j = 1; j <= n; j++){
            string temp = s.substr(i,j);
            if(st.contains(temp) && solve(i+j,s,dp)){
                return dp[i] = 1;
            }
        }

        return dp[i] = 0;
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();

        vector<int> dp(n+1,-1);

        for(auto x: wordDict){
            st.insert(x);
        }

        return solve(0,s,dp);
    }
};
