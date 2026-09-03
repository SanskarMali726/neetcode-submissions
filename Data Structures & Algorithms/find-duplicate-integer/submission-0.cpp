class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        int i;
        for(i=0;i<n;i++){
            if(s.find(nums[i]) != s.end()){
                break;
            }
            s.insert(nums[i]);
        }
        return nums[i];
    }
};
