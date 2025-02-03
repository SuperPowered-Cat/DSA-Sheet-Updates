// leetcode 1752
// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/?envType=daily-question&envId=2025-02-02

class Solution {
public:
    bool check(vector<int>& nums) {
        // set variable to identify whether there are breaks in the array
        // as the array is supposed to be sorted but rotated, there can be
        // at max 1 break, if more then it is not sorted+rotated
        
        int breakdown = 0; // to check breaks

        // if any element is not lesser than the next, break++
        for (int i = 0; i < nums.size(); i++) {
            // nums[(i+1)%nums.size()] for wraparound as rotated array
            if (nums[i] > nums[(i+1) % nums.size()]) breakdown++;
        }

        // if only single or no break then arr is sorted & (maybe) rotated
        if ( breakdown < 2) return true;
        return false;
    }
};
