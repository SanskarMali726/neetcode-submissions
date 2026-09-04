class Solution {
public:
    int helperRob(vector<int>& nums,vector<int>& dp,int maximum){
        
        dp[0] = nums[0];
        dp[1] = nums[1];
        maximum = max(dp[0],dp[1]);

        for(int i = 2; i < nums.size(); i++){
            int temp = nums[i];
            for(int j = i - 2; j >= 0; j--){
                if(temp < dp[j] + nums[i]){
                    temp = dp[j] + nums[i];
                }
            }
            maximum = max(maximum,temp);
            dp[i] = temp;
        }

        return maximum;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        vector<int> dp(nums.size(),-1);
        int maximum = 0;
        return helperRob(nums,dp,maximum);
    }
};
