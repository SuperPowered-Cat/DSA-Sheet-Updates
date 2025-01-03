// leetcode 2270
// https://leetcode.com/problems/number-of-ways-to-split-array/?envType=daily-question&envId=2025-01-03

class Solution {
public:
    long int waysToSplitArray(vector<int>& nums) {
        // total sum of the entire array
        long int sum = 0;
        for (long int x : nums) sum += x;

        // sum of all numbers after i = total sum - prefix[i]
        vector<long int> prefix(nums.size(), 0);
        prefix[0] = nums[0];
        for(long int i = 1; i < nums.size(); i++) {
            prefix[i] = nums[i] + prefix[i-1];
        }

        long int maxways = 0;
        for (long int i = 0; i < nums.size()-1; i++) {
            long int rightsum = sum - prefix[i];
            if (prefix[i] >= rightsum) maxways++;
        }

        return maxways;
    }
};
