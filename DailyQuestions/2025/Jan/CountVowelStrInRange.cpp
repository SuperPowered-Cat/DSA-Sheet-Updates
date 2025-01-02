// leetcode 2559
// https://leetcode.com/problems/count-vowel-strings-in-ranges/?envType=daily-question&envId=2025-01-02

class Solution {
public:
    
    // helper function to verify if a character is alphabet
    // hardcoded, can alternatively use set to avoid seperate func
    // but runtime is O(1) so its fine
    static bool isvowel(char ch) {
        if (ch == 'a') return true;
        else if (ch == 'e') return true;
        else if (ch == 'i') return true;
        else if (ch == 'o') return true;
        else if (ch == 'u') return true;
        else return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // since continuous range, number of elements till i are simply
        // no of elements till i-1 + 1 (if condition met)
        // so, we use a prefix sum of valid strings
        vector<int> prefix(words.size(), 0);
        // setting up the first value of prefix
        // size()-1 because 0 based indexing
        if (isvowel(words[0][0]) && isvowel(words[0][words[0].size()-1])) 
            prefix[0] = 1;
        else prefix[0] = 0;

        // looping to fill the prefix array
        for(int i = 1; i < words.size(); i++) {
            if (isvowel(words[i][0]) && isvowel(words[i][words[i].size()-1])) prefix[i] = prefix[i-1] + 1; // when condition is met
            else prefix[i] = prefix[i-1]; // otherwise same as left ele
        }

        // finally, the answer for each query(l, r) is simply
        // prefix[r] - prefix[l-1]
        // l -1 is happening because written in question, 
        // BOTH RANGE IS INCLUSIVE 
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            // range of quereis is from l to r
            int l = queries[i][0];
            int r = queries[i][1];

            if (l > 0) // if not then simply push prefix[r]
            ans.push_back(prefix[r] - prefix[l - 1]); // formula
            else ans.push_back(prefix[r]);
        }

        // final answer
        return ans;
    }
};
