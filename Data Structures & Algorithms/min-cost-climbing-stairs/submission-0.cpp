class Solution {
public:
    int costs(int n,vector<int>& cost,vector<int>& dp){
       dp[0] = 0;
       dp[1] = 0;

        for(int i = 2; i<= n; i++){
            if(dp[i] != -1){
                return dp[i];
            }

            dp[i] = min(cost[i-1] + dp[i-1], cost[i-2] + dp[i-2]); 
        }

        return dp[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return costs(n,cost,dp);
    }
};
