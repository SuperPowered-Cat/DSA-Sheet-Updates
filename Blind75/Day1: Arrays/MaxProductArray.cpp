// leetcode 152

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // using Kadane algorithm-twice

        // left to right pass
        int max1 = INT_MIN;
        int prod1 = 1;
        for (int i= 0; i<nums.size(); i++) {
            prod1*=nums[i];
            if (max1 < prod1) max1 = prod1;
            if (prod1 == 0) prod1 = 1;
        }

        // right to left pass
        int prod2 = 1;
        int max2 = INT_MIN;
        for (int i = nums.size()-1; i>=0; i--) {
            prod2*=nums[i];
            if (max2 < prod2) max2 = prod2;
            if (prod2 == 0) prod2 = 1;
        }

        // so that we compute the maximum possible product
        // 2 passes due to negative signs changing product from l2r and r2l
        return max(max1, max2);
    }
};
