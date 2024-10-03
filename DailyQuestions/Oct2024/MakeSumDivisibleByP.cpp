// leetcode 1590

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long totalSum = 0;
        for (int i = 0; i < nums.size(); i++) totalSum += nums[i];
        int rem = totalSum%p;
        if (rem == 0) return 0;

        map <int, int> modulo;
        int count = nums.size();
        modulo[0] = -1;
        long curPrefix = 0;
        long curMod;
        for (int i = 0; i < nums.size(); i++) {
            curPrefix += nums[i];
            curMod = curPrefix%p;
            int target = (curMod - rem + p) % p;
            if (modulo.find(target) != modulo.end()) { 
                int index = modulo[target];
                count = min(count, i - modulo[target]);
            }
            modulo[curMod] = i;
        }
        return count == nums.size() ? -1 : count;
    }
};
