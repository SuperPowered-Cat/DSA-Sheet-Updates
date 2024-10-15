// leetcode 2938

class Solution {
public:
    long long minimumSteps(string s) {
        long long count = 0; // total no of balls
        long long bcount = 0; // total no of black balls
        int n = s.length();
        for (char x : s) { // iterating throgh the array incrementing bcount for 1
            if (x == '1') bcount++;
            else count+=bcount; // if white ball is encountered then add bcount to count
            // this automatically ensures cases where multiple times ball has to move
        }
        return count; // final count;

    }
};
