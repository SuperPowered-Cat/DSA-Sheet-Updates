// leetcode 122

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            // if the next stock is higher, we IMMEDIATELY sell and get next
            // so profit is the next stock value - the cost of prev stock
            if (prices[i-1] < prices[i]) profit+=prices[i] - prices[i-1];
        }
        return profit;
    }
};
