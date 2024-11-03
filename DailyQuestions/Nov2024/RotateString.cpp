// leetcode 796

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        string test = s+s;
        return stringCheck(test, goal);
    }

    bool stringCheck(string& a, string& b) {
        int l = 0;
        int r = b.size();
        
        for (int i = 0; i < a.size(); i++) {
            string sub = a.substr(l, r);
            cout << sub << " " << b << endl;
            if (sub == b) return true;
            l++;
        }
        return false;
    }
};
