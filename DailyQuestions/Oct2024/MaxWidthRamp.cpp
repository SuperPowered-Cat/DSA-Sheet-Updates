//leetcode 962

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        
        // bruteforce method - gives tle

        // int maxWidth = 0;
        // for (int i = 0; i < nums.size()-1; i++) {
        //     for (int j = i+1; j < nums.size(); j++) {
        //         if (nums[i] <= nums[j]) {
        //             int temp = j-i;
        //             maxWidth = max(maxWidth, temp);
        //         } 
        //     }
        // }
        // return maxWidth;

        // 2 pointers approach with reverse maximum array

        vector <int> right(nums.size());
        right[nums.size()-1] = nums[nums.size()-1];
        for (int i = nums.size()-2; i>=0; i--) right[i] = max(right[i+1], nums[i]);
        int maxWidth = 0;
        int l = 0, r = 0;
        while (r<nums.size()) {
            while (l<r && nums[l] > right[r]) l++;
            maxWidth = max(maxWidth, r - l);
            r++;
        }
        return maxWidth;
    }
};
