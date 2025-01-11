// leetcode 1400
// https://leetcode.com/problems/construct-k-palindrome-strings/?envType=daily-question&envId=2025-01-11

class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) return false; // cannot be true if size is less
        // this is because minim palindrome will be single single string
        if(s.size() == k) return true; // like example3

        // for a palindrome -> 
        // if even: all frequency of characters should be even
        // if odd: at most one frequency of characters can be odd
        unordered_map<char, int> freqmap;
        unordered_map<char, int> oddchars;
        for(char& ch : s) freqmap[ch]++;

        // now we have the frequency map, can do mathematical reasoning
        int even = 0;
        for (auto [key, value] : freqmap) {
            if (value%2 == 0) even+=value;
            else oddchars[key]++;
        }
        int odd = oddchars.size();
        if (odd>k) return false;
        else return true;
    }
};
