class Solution {
public:

    vector<vector<int>> ans;
    void findCombination(vector<int> &nums,vector<int> &temp,int target,int i){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        else if(target < 0 || i == nums.size()){
            return;
        }
        
        target -= nums[i];
        temp.push_back(nums[i]);
        findCombination(nums,temp,target,i+1);

        while(i + 1 < nums.size() && nums[i] == nums[i + 1]){
            i++;
        }
        target += nums[i];
        temp.pop_back();
        findCombination(nums,temp,target,i+1);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        findCombination(candidates,temp,target,0);
        vector<vector<int>> s(ans.begin(),ans.end());
        return s;
    }
};
