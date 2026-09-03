class Solution {
public:
    vector<vector<int>> ans;

    void findSubset(vector<int>& nums,vector<int>& temp,int i){
        if(i == nums.size()){
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[i]);
        findSubset(nums,temp,i+1);

        temp.pop_back();
        while( i + 1 < nums.size() && nums[i] == nums[i + 1]){
            i++;
        }
        findSubset(nums,temp,i+1);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        findSubset(nums,temp,0);
        return ans;
    }
};
