// leetcode 2779

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int maxlen = 0;
        
        // moving a sliding window
        for (int j = 0; j < nums.size(); j++) {

            // NUMBER ADJUSTED UPTO K IN EITHER DIRECTION
            // shortening window till adjustability is possible
            while (nums[j] > nums[i] + 2*k) i++;

            // updating with maximum
            maxlen = max(maxlen, j - i + 1);
        }
        return maxlen;
    }
};
