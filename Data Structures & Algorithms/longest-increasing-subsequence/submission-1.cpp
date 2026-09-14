class Solution {
public:
    int n;

    int solve(int i, int prevIndex, vector<int>& nums, vector<vector<int>>& dp) {
        if (i >= n)
            return 0;

        if (dp[i][prevIndex + 1] != -1)
            return dp[i][prevIndex + 1];

        int notTake = solve(i + 1, prevIndex, nums, dp);

        int take = 0;

        if (prevIndex == -1 || nums[prevIndex] < nums[i]) {
            take = 1 + solve(i + 1, i, nums, dp);
        }

        return dp[i][prevIndex + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(0, -1, nums, dp);
    }
};
