class Solution {
public:
    int n;
    bool solve(int i,vector<int> &nums,int target){
        if(target == 0){
            return true;
        }
        if(i >= n -1){
            return false;
        }

        target -= nums[i];
        if(solve(i+1,nums,target)) return true;

        target += nums[i];

        return solve(i+1,nums,target);

    
    }

    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        if(sum % 2 != 0){
            return false;
        }

        return solve(0,nums,sum/2);
    }
};
