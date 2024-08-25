class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, max_count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) count++;
            else {
                if (max_count<=count) swap(max_count, count);
                count = 0;
            }
        }
        if (max_count<count) return count;
        return max_count;
    }
};
