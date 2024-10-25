// leetcode 503

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> ans (nums.size(), -1);
        st.push(0);
        for (int i = 0; i < nums.size()*2 ; i++) {
            int index = i%nums.size();
            while (!st.empty() && nums[st.top()] < nums[index]) {
                ans[st.top()] = nums[index];
                st.pop();
            }
            if (i<nums.size()) st.push(index);
        }
        return ans;
    }
};
