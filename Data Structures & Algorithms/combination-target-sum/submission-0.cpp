class Solution {
public:
    vector<vector<int>> ans;

    void findNumbers(vector<int>& nums,vector<int>& temp, int target,int i) {
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        else if(target < 0 || i == nums.size()){
            return;
        }

        target -= nums[i];
        temp.push_back(nums[i]);
        findNumbers(nums,temp,target,i);

        temp.pop_back();
        target += nums[i];  
        findNumbers(nums,temp,target,i+1);
        

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        findNumbers(nums,temp,target,0);
        return ans;
    }
};
