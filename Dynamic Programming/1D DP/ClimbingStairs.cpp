// leetcode 70

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        int x = fib(n, dp);
        return x;
    }

    int fib(int n, vector<int>& dp) {
        if (n<=1) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = fib(n-1, dp) + fib(n-2, dp);
    }
};
