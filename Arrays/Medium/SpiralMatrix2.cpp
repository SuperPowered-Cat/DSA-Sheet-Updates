// Leetcode 59

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0)); // initialised matrix nxn with zeroes
        int left = 0;
        int right = n-1;
        int top = 0;
        int bottom = n-1;
        int num = 1;
        
        while (num <= n*n) {

            // top row
            for (int i = left; i <= right; i++) matrix[top][i] = num++;
            top++;

            // rightmost column
            for (int i = top; i <= bottom; i++) matrix[i][right] = num++;
            right--;

            // bottom row
            if (top<=bottom)
            for (int i = right; i>=left; i--) matrix[bottom][i] = num++;
            bottom--;

            // leftmost column
            if (left<=right)
            for (int i = bottom; i>=top; i--) matrix[i][left] = num++;
            left++;
        }
        return matrix;
    }
};
