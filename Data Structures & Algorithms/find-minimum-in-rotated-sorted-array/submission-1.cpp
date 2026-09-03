class Solution {
public:
    int bs(vector<int>&nums,int start,int end){
        int mid = start+(end-start)/2;

        if(start == end){
            return nums[start];
        }
        int min;

        if(nums[mid] < nums[end]){
            min = bs(nums,start,mid);
        }
        else{
            min = bs(nums,mid+1,end);
        }
        return min;
    }

    int findMin(vector<int> &nums) {
        int n = nums.size();
        return bs(nums,0,n-1);
    }
};
