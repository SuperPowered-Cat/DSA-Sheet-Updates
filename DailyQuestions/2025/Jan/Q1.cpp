// Maximum score after splitting string
// leetcode 1422
// https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/?envType=daily-question&envId=2025-01-01

class Solution {
public:
    int maxScore(string s) {
        // edge case if no split
        if (s.size() < 2) return 0;
        
        // prefix sum of all ones
        vector<int> maxone (s.size(), 0);
        
        // this is because ones at right = totalones - prefix sum[i]
        
        // finding totalones
        int totalones = 0;
        for (auto x : s) if (x == '1') totalones++;

        // now filling maxones
        if (s[0] == '1') maxone[0] = 1;
        else maxone[0] = 0;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '1') maxone[i] = maxone[i-1] + 1; // increment
            else maxone[i] = maxone[i-1]; // same as last if not 1
        }

        int maxscore = 0; // final ans
        int zeroscore = 0; // zeroes from left
        for (int i = 0; i < s.size() - 1; i++) { 
        // -1 because no split at the last element
            if (s[i] == '0') zeroscore++;

            // score = zeronum + (totalones - ones at left)
            maxscore = max(maxscore, zeroscore + totalones - maxone[i]);
        }

        // final answer 
        return maxscore;
    }
};
