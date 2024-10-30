// leetcode 1277

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // Get the number of rows (r) and columns (c)
        int r = matrix.size();
        int c = matrix[0].size();

        // Initialize a DP table with dimensions (r+1) x (c+1) to handle boundaries
        vector<vector<int>> dp(r + 1, vector<int>(c + 1, 0));
        int ans = 0; // Initialize the count of square submatrices

        // Iterate through each cell in the original matrix
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                // If the current cell in the matrix is 1
                if (matrix[i][j] == 1) {
                    // Update the DP table using the transition formula
                    dp[i + 1][j + 1] = min({dp[i][j + 1], dp[i + 1][j], dp[i][j]}) + 1;
                    // Accumulate the count of squares
                    ans += dp[i + 1][j + 1];
                }
            }
        }
        return ans; // Return the total count of square submatrices
    }
};
