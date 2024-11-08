// leetcde 1829

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> preXor;
        preXor.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) preXor.push_back(nums[i] ^ preXor[i-1]);
        int maxXor = pow(2, maximumBit) - 1;
        vector<int> ans;
        for (int i = preXor.size()-1; i >= 0; i--) ans.push_back(preXor[i] ^ maxXor);
        return ans;
    }
};
