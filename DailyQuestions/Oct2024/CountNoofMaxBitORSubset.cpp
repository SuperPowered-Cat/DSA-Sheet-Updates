// leetcode 2044

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int x = nums[0];
        for (auto y : nums) {
            x = x | y;
        } 
        return back(nums, 0, 0, x);
    }
private:
    int back(vector<int>& nums, int index, int currOr, int maxOr) {
        if (nums.size() == index) {
            if (currOr == maxOr) return 1;
            else return 0;
        }
        int a = back(nums, index+1, currOr | nums[index], maxOr);
        int b = back(nums, index+1, currOr, maxOr);
        return a + b;
    }
};
