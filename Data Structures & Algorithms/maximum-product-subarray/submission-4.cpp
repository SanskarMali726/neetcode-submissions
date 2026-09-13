class Solution {
public:
    //https://www.youtube.com/watch?v=hnswaLJvr6g - solution if not understand
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maximum = INT_MIN;
        int prefix = 1;
        int suffix = 1;
        for(int i = 0; i < n; i++){
            
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;

            prefix *= nums[i];

            suffix *= nums[n - i - 1];

            maximum = max(maximum, max(prefix,suffix));
        }

        return maximum;
    }
};
