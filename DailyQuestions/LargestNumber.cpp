// leetcode 

// **Q: Largest Number**

// Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
// Since the result may be very large, so you need to return a string instead of an integer.

// Example 1:
// Input: nums = [10,2]
// Output: "210"

// Example 2:
// Input: nums = [3,30,34,5,9]
// Output: "9534330"
 
// Constraints:
// 1 <= nums.length <= 100
// 0 <= nums[i] <= 109


// CODE ->

// custom sort
    bool check(int a, int b) {
        string aStr = to_string(a);
        string bStr = to_string(b);
        // seeing whether a+b is greater or b+a is greater as string value for max element
        if ((aStr + bStr) > (bStr + aStr)) {
            return true;
        }
        return false;
    }

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), check); // using a custom sort where we check both cases
        if (nums[0] == 0) return "0";
        string answer = "";
        for (int i = 0; i < nums.size(); i++) {
            answer= answer + to_string(nums[i]);
        }
        return answer;
    }
};