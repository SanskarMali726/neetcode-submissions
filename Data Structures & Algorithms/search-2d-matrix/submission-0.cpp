class Solution {
public:
    //This solution has time complexity of O(m * log n)
    // int bs(vector<int>nums, int target , int start , int end){
    //     if(start <= end){
    //         int mid = start + (end-start)/2;
    //         if(nums[mid] < target){
    //             return bs(nums,target,mid+1,end);
    //         }
    //         else if(nums[mid] > target){
    //             return bs(nums,target,start,mid-1);
    //         }
    //         else{
    //             return nums[mid];
    //         }
    //     }
    //     return -1;
    // }
    bool bs(vector<vector<int>>& matrix, int target , int start , int end , int n){
        if(start <= end){
            int mid = start + (end-start)/2;
            int row = mid/n;
            int col = mid%n;
            if(matrix[row][col] < target){
                return bs(matrix,target,mid+1,end,n);
            }
            else if(matrix[row][col] > target){
                return bs(matrix,target,start,mid-1,n);
            }
            else{
                return true;
            }
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //This solution has time complexity of O(m * log n)
    //     int n = matrix.size();
    //     int ans;
    //     for(int i=0;i<n;i++){
    //         ans = bs(matrix[i],target,0,matrix[i].size()-1);
    //         if(ans == target){
    //             return true;
    //         } 
    //     }
    //     return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int total = (m*n)-1;
        return bs(matrix,target,0,total,n);
    }
};
