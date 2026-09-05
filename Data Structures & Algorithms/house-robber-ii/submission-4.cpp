class Solution {
public:

    int helper(vector<int>& nums,int str, int end){
        vector<int> dp(nums.size()-1);

        dp[0] = nums[str];
        dp[1] = max(nums[str], nums[str+1]);

        for(int i = str+2, j = 2; i < end; i++ , j++){
                dp[j] = max(dp[j-1], nums[i] + dp[j-2]);
        }

        return dp[nums.size()-2];
    }


    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);

        return max(helper(nums,1,n),helper(nums,0,n-1));

    
    }
};
