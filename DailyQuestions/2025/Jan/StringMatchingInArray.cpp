//leetcode 1408
// https://leetcode.com/problems/string-matching-in-an-array/?envType=daily-question&envId=2025-01-07

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> ans;
        
        for(int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i == j) continue;
                if(isSub(words[i], words[j])) ans.insert(words[i]); 
            }
        }

        vector<string> finalans;
        for (auto x : ans) finalans.push_back(x);
        return finalans;
    }

    bool isSub(const string& a, const string& b) {
        return b.find(a) != string::npos;
    }
};
