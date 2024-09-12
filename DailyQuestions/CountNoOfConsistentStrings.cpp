class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> test(allowed.begin(), allowed.end());
        int count = 0;
        
        for (const string & x : words) {
            bool check = true;
            for (char c : x) {
                if (test.find(c) == test.end()) {
                    check = false;
                    break;
                }
            }
            if (check) count++;
        }
        return count;
    }
};
