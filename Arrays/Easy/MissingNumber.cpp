class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() + 1;
        int sum = (n*(n-1))/2;
        int arrSum = 0;
        for (int i = 0; i<n-1; i++) {
            arrSum += nums[i];
        }
        return sum-arrSum;
    }
};
