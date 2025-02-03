// leetcode 3151 
// https://leetcode.com/problems/special-array-i/?envType=daily-question&envId=2025-02-01

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        // different parity == the two numbers either being odd or even
        // but together, ie a&b both odd or both even = same parity

        // if there is only 1 or no element in the array, then special
        if (nums.size() < 2) return true;

        // traversing each possible adjacent and then checking parity
        int n1 = 0, n2 = 1;
        while (n2 < nums.size()) {
            if (nums[n1]%2 == 0) {
                // if both even then false
                if (nums[n2]%2 == 0) return false;
            }
            else {
                // if bboth odd then false
                if(nums[n2] % 2 == 1) return false;
            }
            n1++;
            n2++;
        } 

        //otherwise true
        return true;

    }
};
