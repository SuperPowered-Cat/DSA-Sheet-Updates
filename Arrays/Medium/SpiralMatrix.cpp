// Leetcode 54

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //     m x n
        // rows x columns


        int m = matrix.size(); // rows
        int n = matrix[0].size(); // columns
        int top = 0, left = 0;
        int bottom = m-1, right = n-1;
        vector<int> result;

        // excecutes till last element
        while (top <= bottom && left<=right) {
        
            // first row
            for (int i = left; i <= right; i++) result.push_back(matrix[top][i]);
            top++; 

            // then rightmost column
            for (int i = top; i <= bottom; i++) result.push_back(matrix[i][right]);
            right--;

            // bottom row
            if(top<=bottom) //edgecase
            for (int i = right; i >= left; i--) result.push_back(matrix[bottom][i]);
            bottom--;

            // leftmost column
            if (left<=right) //edgecase
            for (int i = bottom; i >= top; i--) result.push_back(matrix[i][left]);
            left++;

        }
        return result;
    }
};
