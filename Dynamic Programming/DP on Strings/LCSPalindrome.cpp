// leetcode 516

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string og = s;
        reverse(s.begin(), s.end());
        vector<vector<int>> DP(s.size()+1, vector<int> (s.size()+1, -1));
        return lcs(0, 0, og, s, DP);
    }

    int lcs(int i, int j, string& og, string& rev, vector<vector<int>>& DP) {
        if (i>=og.size()) return 0;
        if (j>=og.size()) return 0;
        
        if(DP[i][j] != -1) return DP[i][j];

        if (og[i] == rev[j]) return DP[i][j] = 1 + lcs(i+1, j+1, og, rev, DP);

        return DP[i][j] = max(lcs(i+1, j, og, rev, DP), lcs(i, j+1, og, rev, DP));
    }
};
