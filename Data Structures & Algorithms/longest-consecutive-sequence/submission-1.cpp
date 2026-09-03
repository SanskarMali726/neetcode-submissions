class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int max_size=1;
        int size =1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]+1 == nums[i+1]){
                size += 1;
                
            }
            else if(nums[i] == nums[i+1]){
                continue;
            }
            else{
                if(size>max_size){
                    max_size = size;
                    size = 1;
                }
                else{
                size = 1;
                }
            }
        }
        return max(max_size,size);

    }
};
