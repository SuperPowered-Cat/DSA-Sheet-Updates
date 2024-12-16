// leetcode 3264

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minhp;
        for (int i = 0; i < nums.size(); i++) minhp.push({nums[i], i});
        for (int i = 0; i < k; i++) {
            auto [ele, ind] = minhp.top();
            minhp.pop();
            ele=ele*multiplier;
            nums[ind] = ele;
            minhp.push({ele, ind});
        }
        return nums;
    }
};
