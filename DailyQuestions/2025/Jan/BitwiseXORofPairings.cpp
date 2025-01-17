// leetcode 2425
// https://leetcode.com/problems/bitwise-xor-of-all-pairings/?envType=daily-question&envId=2025-01-16

class Solution {
public:
    long long xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        vector<long long >nums3;
        // a xor x = 0
        // a xor 0 = a
        // each element of nums1 will be used in n1 calculations
        // where n1 is size of n1
        // similarly each element of nums2 will be used n2 times
        // if the size of n1 is even, the entire array cancels out
        // similarly if the size of n2 is even, entire cancels out
        
        int xor1 = 0, xor2 = 0;
        for (auto n1 : nums1) xor1^=n1;
        for (auto n2 : nums2) xor2^=n2;
        
        // if both nums1 and nums2 even then 0 returned
        if (nums1.size() % 2 == 0 && nums2.size() % 2 == 0) { 
           return 0;
        } 
        
        // if nums1 is even, the other nums2 is   
        else if (nums1.size() % 2 == 0) {
            return xor1;
        } 
        
        // if nums2 is odd, nums1 will be returned  
        else if (nums2.size() % 2 == 0) {
            return xor2;
        }

        // both odd so we return xor of all
        else return xor1^xor2;
    }
};
