class Solution {
public:
    
    // BRUTEFORCEEEEEEE
    // int singleNumber(vector<int>& nums) {
    //     if (nums.size()<2) return nums[0];
    //     for (int i = 0; i <nums.size(); i++) {
    //         int count = 0;
    //         for (int j = 0; j<nums.size(); j++) {
    //             if (nums[i] == nums[j]) count++; 
    //         }
    //         if (count == 1) return nums[i];
    //     }
    //     return 0;
    // }  

        // CAN ALSO USE HASHING BTWWW


        // Assume the given array is: [4,1,2,1,2]
        // XOR of all elements = 4^1^2^1^2
        // = 4 ^ (1^1) ^ (2^2)
        // = 4 ^ 0 ^ 0 = 4^0 = 4
        // Hence, 4 is the single element in the array.

        // XOR TYPE SHIT
    int singleNumber(vector<int>& nums) {
        int xornum = 0;
        for (int i = 0; i < nums.size(); i++) xornum = xornum ^ nums[i];
        return xornum;
    }
};
