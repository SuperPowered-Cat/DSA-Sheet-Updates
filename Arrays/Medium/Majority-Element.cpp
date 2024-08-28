class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //bruteforce
        // for (int i = 0; i < nums.size(); i++) {
        //     int count = 0;
        //     for (int j = 0; j < nums.size(); j++) {
        //         if (nums[j] == nums[i]) count++;
        //     }

        //     if (count > nums.size()/2) return nums[i];
        // }

        // return -1;

        // Could also use Hashing for better time management.

        // moore voting algorithm.
        int count = 0;
        int candidate;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            }
            else if (nums[i] == candidate) count ++;
            else count--;
        }   
        count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == candidate) count++;
        } 

        if (count > nums.size()/2) return candidate;
        return -1;
    }
};
