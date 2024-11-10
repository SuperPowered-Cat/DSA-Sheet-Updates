// leetcode 3097

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        // learn bit manipulation
        // strengthen sliding window

        int minimum = INT_MAX;
        int l = 0, r = 0; // sliding window
        vector<int> count (32, 0); // bit count of set bits (till size 32)
        
        while ( r < nums.size()) {
            updatebits(count, nums[r], 1); // helper func to set the bits
            
            while (l <= r && convertbits(count) >= k) { // convert to digit
                minimum = min(minimum, r - l + 1);
                updatebits(count, nums[l], -1);
                l++; // reduce window and try to get minimum length 
            }
            
            r++; // increase window
        }

        if (minimum == INT_MAX) return -1; // edgecase
        return minimum;

    }

    void updatebits(vector<int>& count, int x, int delta) {
        for (int i = 0; i < 32; i++) {
            if ((x>>i)&1) count[i] +=delta;
        }
    }

    int convertbits(vector<int>& count) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if (count[i] != 0) res |= 1 << i;
        }
        return res;
    }
};
