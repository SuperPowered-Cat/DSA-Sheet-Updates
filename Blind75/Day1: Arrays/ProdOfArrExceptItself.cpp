// leetcode 238

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // prefix sum
        vector<int> prefix(nums.size(), 1);
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) prefix[i] = nums[i]*prefix[i-1];
        
        // suffix sum
        vector<int> suffix(nums.size(), 1);
        suffix[nums.size()-1] = nums[nums.size()-1];
        for (int i = nums.size()-2; i>=0; i--) suffix[i] = nums[i]*suffix[i+1];

        vector<int> ans(nums.size());
        ans[0] = suffix[1];
        ans[nums.size()-1] = prefix[nums.size()-2];
        for (int i = 1; i < nums.size() - 1; i++) {
            ans[i] = prefix[i-1]*suffix[i+1];
        }

        return ans;
    }
};
