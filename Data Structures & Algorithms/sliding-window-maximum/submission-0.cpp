class Solution {
public:
    int checkmax(vector<int>& nums,int s,int e){
        int maxNum=INT_MIN;
        for(int i=s;i<=e;i++){
            maxNum = max(maxNum,nums[i]);
        }
        return maxNum;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int l=0;
        int r=k-1;
        while(r<nums.size()){
            int ans = checkmax(nums,l,r);
            result.push_back(ans);
            l++;
            r++;
        }
        return result;
    }
};
