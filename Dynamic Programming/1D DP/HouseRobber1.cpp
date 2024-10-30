// leetcode 198

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size()+1, -1);
        return recur(nums.size()-1, nums, dp);
    }

    int recur(int i, vector<int> nums, vector<int>& dp) {
        if (i<0) return 0;
        if (dp[i] != -1) return dp[i];
        return dp[i] = max((nums[i] + recur(i-2, nums, dp)), recur(i-1, nums, dp));
    }
};
