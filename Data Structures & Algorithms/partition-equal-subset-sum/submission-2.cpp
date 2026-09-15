class Solution {
public:
    int n;  // Stores the size of the array

    /*
        solve(i, target) means:

        Starting from index 'i',
        can we select some elements from nums[i...n-1]
        such that their sum is exactly 'target'?

        dp[i][target] stores the answer for this state.
        -1  -> state has not been calculated yet
         0  -> impossible
         1  -> possible
    */
    bool solve(int i, vector<int>& nums, int target,
               vector<vector<int>>& dp) {

        // If target becomes 0, we have successfully
        // found a subset whose sum is exactly the required sum.
        if(target == 0)
            return true;

        // If we have gone beyond the last index,
        // but target is still not 0, we cannot form the target.
        if(i >= n)
            return false;

        // If we have already solved this (i, target) state,
        // return the stored answer instead of calculating again.
        if(dp[i][target] != -1)
            return dp[i][target];

        // Option 1: TAKE nums[i]
        bool take = false;

        /*
            We can take nums[i] only if it does not make
            the target negative.

            If we take nums[i], the remaining target becomes:

                target - nums[i]

            Then we move to the next index.
        */
        if(nums[i] <= target) {
            take = solve(i + 1,
                         nums,
                         target - nums[i],
                         dp);
        }

        // Option 2: DON'T TAKE nums[i]
        /*
            We simply skip the current element
            and move to the next index.

            Since we didn't take nums[i],
            target remains unchanged.
        */
        bool notTake = solve(i + 1,
                             nums,
                             target,
                             dp);

        /*
            If either choice works, then the current state works.

                take    -> using nums[i] gives the answer
                notTake -> skipping nums[i] gives the answer

            Store the result in dp[i][target] so that
            we don't solve the same state again.
        */
        return dp[i][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {

        // Store the number of elements
        n = nums.size();

        // Calculate the total sum of all elements
        int sum = 0;

        for(int x : nums)
            sum += x;

        /*
            We need to divide the array into two subsets
            having equal sums.

            Therefore:

                subset1 + subset2 = sum
                subset1 = subset2

            So the total sum must be even.

            Example:
                sum = 10
                each subset must have sum = 5

                sum = 11
                impossible to divide into two equal integers.
        */
        if(sum % 2 != 0)
            return false;

        // We only need to find one subset
        // whose sum is exactly half of the total sum.
        int target = sum / 2;

        /*
            dp[i][target]

            Rows    -> index i
            Columns -> remaining target

            target + 1 because target can range from:
                0, 1, 2, ..., target

            Initially every state is -1,
            meaning "not calculated yet".
        */
        vector<vector<int>> dp(
            n,
            vector<int>(target + 1, -1)
        );

        // Start from index 0 and try to form 'target'
        return solve(0, nums, target, dp);
    }
};