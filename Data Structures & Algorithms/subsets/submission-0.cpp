class Solution {
public:
    vector<vector<int>> ans;
    void findSubset(vector<int>& nums,vector<int>& temp, int i){
        if(i == nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        findSubset(nums,temp,i+1);

        temp.pop_back();
        findSubset(nums,temp,i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        findSubset(nums,temp,0);

        return ans;
    }
};
