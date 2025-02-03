// leetcode 3105
// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/?envType=daily-question&envId=2025-02-03

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        // edge case if no element
        if (nums.size() <= 0) return 0;

        // setting up the max incrementing subarray, and max decr subarray
        // also setting up running sum of incr and decr subarray
        int incrMax = 1, decrMax = 1;
        int tempIncr = 1, tempDecr = 1;
        
        // iterating and modifying tempIncr and tempDecr in a single loop
        for (int i = 1; i < nums.size(); i++) {
            
            // first case, incrementing
            if (nums[i] > nums[i-1]) {
                tempIncr++; // increment count increases
                tempDecr = 1; // decrement resets 
            }
            else if (nums[i] < nums[i-1]) {
                tempDecr++; // decrement count increases
                tempIncr = 1; // increment resets
            }
            else {
                // both reset
                tempIncr = 1;
                tempDecr = 1;
            }

            // updating max values
            incrMax = max(incrMax, tempIncr);
            decrMax = max(decrMax, tempDecr);
        } 

        // have to return max incr OR decr, so returning max b/w the two
        return max(incrMax, decrMax);
    }
};
