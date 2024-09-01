class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        if (original.size()!=m*n) {
            return vector<vector<int>>();
        }
        vector <vector <int>> res(m, vector <int>(n));
        for (int i = 0; i < m*n; i++) {
            // using comparision - i/n will give row number and i%n will give column number.
            // using n because column number.
            res[i/n][i%n] = original[i];
        }
        return res;

    }
};
