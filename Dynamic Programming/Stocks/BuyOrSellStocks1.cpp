// leetcode 121

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (min>=prices[i]) min = prices[i]; // first setting up the min value
            if (prices[i] - min > profit) profit =prices[i] - min; // now profit
            // if (profit<0) profit = 0;
        }
        return profit;
    }
};
