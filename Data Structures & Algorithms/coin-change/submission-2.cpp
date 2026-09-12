class Solution {
public:

    int f(int i, int target,vector<int> &nums,vector<vector<int>> &dp){
        if(i == 0){
            if( target % nums[i] == 0) return dp[i][target] = target / nums[i];
            return 1e9;
        }

        if(dp[i][target] != -1) return dp[i][target];

        int notTake = 0 + f(i - 1,target,nums,dp);
        int take = INT_MAX;

        if(nums[i] <= target){
            take = 1 + f(i,target-nums[i],nums,dp);
        }

        return dp[i][target] = min(notTake,take);
        
    }       

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = f(n-1,amount,coins,dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};
