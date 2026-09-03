class Solution {
public:
    vector<vector<int>> ans;
    void findCombination(vector<int>& nums, vector<int>& temp, vector<bool> &used){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int j = 0; j < nums.size(); j++){
            if(used[j]) continue;
            used[j] = true;
            temp.push_back(nums[j]);
            findCombination(nums,temp,used);

            used[j] = false;
            temp.pop_back();
        }
       
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        vector<int> temp;
        findCombination(nums,temp,used);
        return ans;
    }
};
