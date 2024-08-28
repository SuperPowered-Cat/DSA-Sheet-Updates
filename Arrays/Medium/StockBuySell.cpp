class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // keep a variable x which points to the minimum (stored as
        // a large value) and then update if it is lesser than the
        // element in the array.

        int min = INT_MAX;
        int profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (min>=prices[i]) min = prices[i];
            if ((prices[i] - min) > profit) profit = prices[i]-min;
            // if (profit < 0) profit = 0;
        }
        return profit;
    }
};
