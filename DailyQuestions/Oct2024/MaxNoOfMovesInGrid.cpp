// leetcode 2684

    class Solution {
    public:

        const int directions[3] = {-1, 0, +1}; // constant for each call

        int maxMoves(vector<vector<int>>& grid) {
            int m = grid.size(); // no of rows
            int n = grid[0].size(); // no of columns
            vector<vector<int>> dp(m, vector<int>(n, -1));

            int ans = 0;
            for (int i = 0; i < m; i++) {
                int movesDone = recur(i, 0, dp, grid);
                ans = max(ans, movesDone);
            }

            return ans;
        }

        // helper function to do recursive top-down approach with the matrix as cache
        int recur(int r, int c, vector<vector<int>>& dp, vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();

            if (dp[r][c] != -1) return dp[r][c];

            int moves = 0;

            for (auto d : directions) {
                int newr = r+d;
                int newc = c+1;

                // main part of the ideation, getting this without help :')
                // we move forward the next column and apply all the diff directions
                if (newr>= 0 && newc>=0 && newr<m && newc <n && grid[r][c] < grid[newr][newc]) {
                    moves = max(moves, 1 + recur(newr, newc, dp, grid));
                }
            }
            return dp[r][c] = moves;
        }
        
    };
