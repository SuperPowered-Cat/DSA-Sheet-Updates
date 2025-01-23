// leetcode 1267
// https://leetcode.com/problems/count-servers-that-communicate/description/?envType=daily-question&envId=2025-01-23

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        // making a vector array for storing rows and columns 
        vector<int> rowArr(grid.size(), 0);
        vector<int> colArr(grid[0].size(), 0);

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    rowArr[r]++;
                    colArr[c]++;
                }
            }
        }
        // now rowArr[i] shows number of servers at row i
        // same with colArr[i]

        // value of the final ans
        int communicable = 0;

        // we will once again traverse the array and compute how many
        // servers can actually communicate or not

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {// if there exists a server
                    // we will check if there is another server
                    if (rowArr[r] > 1) communicable++; // increment 
                    else if (colArr[c] > 1) communicable++; // same
                }
            }
        }
        
        return communicable;


    }
};
