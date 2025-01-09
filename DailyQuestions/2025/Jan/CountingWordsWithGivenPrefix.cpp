// leetcode 2185
// https://leetcode.com/problems/counting-words-with-a-given-prefix/?envType=daily-question&envId=2025-01-09

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (const string& word : words ) if (isPrefix(pref, word))count++;
        return count;
    }
    bool isPrefix(string pref, string main) {
        if (main.substr(0, pref.size()) == pref) return true;
        return false;
    } 
};
