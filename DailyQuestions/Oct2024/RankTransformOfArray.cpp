// leetcode 1331

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set <int> s(arr.begin(), arr.end());
        vector <int> unique(s.begin(), s.end());
        unordered_map<int, int> freqUnique;
        for (int i = 0; i < unique.size(); i++) freqUnique[unique[i]] = i+1;
        vector <int> result;
        for (int x : arr) result.push_back(freqUnique[x]);
        return result;
    }
};
