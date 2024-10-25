// leetcode 496

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack <int> st; // using monotonic stack
        map <int, int> mp; // map to store the keywise greatest elements
        for (int i = nums2.size()-1; i >= 0; i--) {
            while (!st.empty()&& st.top() <= nums2[i])
                st.pop();
            if (!st.empty()) mp[nums2[i]] = st.top();
            else mp[nums2[i]] = -1;
            st.push(nums2[i]);
        }

        vector<int> ans; // storing ans in this array
        for (auto x: nums1) ans.push_back(mp[x]);
        return ans;
    }
};
