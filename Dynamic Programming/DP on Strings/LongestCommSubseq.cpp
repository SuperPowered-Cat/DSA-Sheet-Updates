// leetcode 1143

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp (text1.size()+1, vector <int> (text2.size()+1, -1));
        return recur(0, 0, text1, text2, dp);
    }
    // top down approach
    int recur(int r, int c, string& t1, string& t2, vector<vector<int>>& dp) {
        
        if (r>=t1.size()) return 0;
        if (c>=t2.size()) return 0;

        if (dp[r][c] != -1) return dp[r][c];

        // when same
        if (t1[r] == t2[c])
            return dp[r][c] = 1 + recur(r+1, c+1, t1, t2, dp);
        // when different
        else
            return dp[r][c] = max(recur(r+1, c, t1, t2, dp), recur(r, c+1, t1, t2, dp));
    }
};
