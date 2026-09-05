class Solution {
public:

    // Solves plain (non-circular) house robber for houses in range [str, end]
    // Returns the max loot achievable from nums[str..end]
    int helper(vector<int>& nums, int str, int end) {
        // dp[j] = best loot achievable using houses nums[str..str+j]
        // NOTE: sized off nums.size()-1 regardless of the actual [str,end] range
        vector<int> dp(nums.size() - 1);

        // Base cases: 1 house -> take it, 2 houses -> take the better one
        dp[0] = nums[str];
        dp[1] = max(nums[str], nums[str + 1]);

        // i = index into nums (real house), j = index into dp (local index)
        // CAUTION: "i <+ end" is parsed as "i < (+end)", i.e. "i < end" —
        // the '+' is unary plus, NOT part of a "<=" operator.
        // This is stricter than "i <= end" — the loop now stops one
        // iteration earlier than a "<=" version would.
        for (int i = str + 2, j = 2; i < end; i++, j++) {
            // rob/skip decision: skip house i (dp[j-1]) vs rob it (nums[i] + dp[j-2])
            dp[j] = max(dp[j - 1], nums[i] + dp[j - 2]);
        }

        // Final answer sits at the last filled slot of dp
        // NOTE: only correct when str == 0 and the loop fills all the way
        // up to dp[nums.size()-2]; depends on how far the loop above actually ran
        return dp[nums.size() - 2];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        // Trivial cases: no circular adjacency conflict possible
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        // Circular houses: house 0 and house n-1 are adjacent, so rob either
        // houses [1, n-1] or houses [0, n-2], and take the better result
        return max(helper(nums, 1, n), helper(nums, 0, n - 1));
    }
};