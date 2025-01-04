// leetcode 1930
// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/?envType=daily-question&envId=2025-01-04

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int count = 0;

        // looping for all possible 3 size palindromes 
        // first and last must be same character, so X_X pattern
        // then simply counting all unique characters between X and X
        for (char c = 'a'; c <= 'z'; c++) {
            int first = -1;
            int last = -1;
            
            // first finding out the first and last characters
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == c) {
                    if (first == -1) first = i;
                    last = i;
                } 
            }
            
            // if a valid X_X is found 
            if (last != -1 && first != -1) {
                unordered_set<char> uniquechar;
            
                // putting all the UNIQUE characters between 1st and last
                for (int i = first+1; i < last; i++) {
                    uniquechar.insert(s[i]); // set for unique values
                }

                count += uniquechar.size(); // updating count for each X_X
            }
        }

        // final answer
        return count;
    }
};
