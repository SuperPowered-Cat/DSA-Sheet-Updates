// leetcode 1368
// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/?envType=daily-question&envId=2025-01-18

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        // 2d vector of directions right, left, down, up
        int numrow = grid.size(), numcol = grid[0].size(); 
        // no of rows and colums in input grid
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        // a priority queue which stores {cost, row, col} ordered by cost
        // using greater<> to have a minheap which stores least cost
        pq.push({0, 0, 0}); // initial cost 0;
        vector<vector<int>> minCost (numrow, vector<int> (numcol, INT_MAX));
        // creating a minCost grid
        // here each value of grid is initially set as infinite
        minCost[0][0] = 0; // starting cell so 0 cost

        // now we traverse through the pq and explore cells based on cost
        // lowest cost cells are processed first, helping us prioritise
        // for each cell, evaluating all 4 neighbouring cells
        
        // for this we calculate cost to reach neighbor by adding current
        // cost + cost of moving to neighbor
        
        // if new cost is lower than the current cost in minCost, we 
        // update minCost as we found a better cost

        // this will continue till pq is empty and all cells are cleared
        // minCost bottom-right will store the answer of minimum cost

        while (!pq.empty())  {
            auto curr = pq.top();
            pq.pop();
            int cost = curr[0];
            int r = curr[1];
            int c = curr[2];

            // skipping if we found better path to cell
            if (minCost[r][c] != cost) continue;

            for (int d = 0; d < 4; d++) {
                int newr = r + dir[d][0]; // the row of the dth ele of dir
                int newc = c + dir[d][1]; // new column of dth ele of dir
                if (newr<numrow && newc < numcol && newr>=0 && newc >=0){
                    int newcost = cost; 
                    // if directions are same then no need to add cost
                    // -1 ecause in grid, directions start from 1
                    if (d == grid[r][c] - 1) newcost+=0;
                    else newcost+=1; // if not same then cost++;

                    // if this found cost is better than original cost
                    if (newcost < minCost[newr][newc]) {
                        minCost[newr][newc] = newcost;
                        pq.push({newcost, newr, newc});
                    }
                }
            }
        }
        return minCost[numrow-1][numcol-1];
    }
};
