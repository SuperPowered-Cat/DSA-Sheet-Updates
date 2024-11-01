// leetcode 1957

class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        ans.push_back(s[0]);
        int count = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ans.back()) {
                count++;
                if (count<3) ans.push_back(s[i]);
            }
            else {
                count = 1;
                ans.push_back(s[i]);
            }
        }
        return ans;
    }

    // void remove(string& s, char x) {
    //     s.erase(s.find(x), 1);
    // }
};
