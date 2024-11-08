// leetcode 2275

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int temp = 0;
            for (auto x : candidates) if (x & (1 << i)) temp++;
            ans = max(ans, temp);
        }
        return ans;
    }
};
