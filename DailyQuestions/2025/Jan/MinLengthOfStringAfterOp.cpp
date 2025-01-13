// leetcode 3223
// https://leetcode.com/problems/minimum-length-of-string-after-operations/?envType=daily-question&envId=2025-01-13

class Solution {
public:
    int minimumLength(string s) {
        // making a frequency map
        // for any character, minimum frequency should be 3
        // and for each character whose frequency>=3, we decriment 2
        // so simply make map and for each element of map :
        // if value <3 add to ans
        // if >=3 then -2 until its <3 then add

        // frequency map
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++; // automatically adds frequency
        int minimum = 0;
        for (auto [ch, fre] : freq) { // checking fre for each in freq
            if (fre < 3) minimum+=fre; // less than 3, no operation
            else {
                while (fre>=3) fre = fre-2; // more than 3, so we remove 2
                // removing 2 because in each operation, we remove L and R
                // therefore -2 each time
                minimum+=fre; // updating when while loop is closed
            }
        }
        return minimum;
    }
};
