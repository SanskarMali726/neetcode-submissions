class Solution {
public:
    int bs(vector<int>& nums,int target,int start,int end){
        if(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] < target){
                return bs(nums,target,mid+1,end);
            }
            else if(nums[mid] > target){
                return bs(nums,target,start,mid-1);
            }
            else{
                return mid;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return bs(nums,target,0,nums.size()-1);
    }
};
