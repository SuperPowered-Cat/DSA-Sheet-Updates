// leetcode 217

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s (nums.begin(), nums.end());
        return (nums.size() != s.size());
    }
};
