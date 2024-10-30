// leetcode 213

class Solution {
public:
    int rob(vector<int>& nums) {
        // same as house robber 1 but done twice
        // this is because 1st and last are adjacent
        
        if (nums.size() == 1) return nums[0]; // edgecase

        // twp recursion func so 2 arrays
        vector <int> dp (nums.size()+1, -1); 
        vector <int> dp2 (nums.size()+1, -1); 

        // two calls
        int x = recur(nums.size()-2, nums, dp); // including all except last
        int y  = recur2(nums.size()-1, nums, dp2); // including all except first
        
        // returning the maximum amount
        return max(x, y);
    }

    int recur(int i, vector<int>& nums, vector<int>& dp) {
        if (i<0) return 0; // not including second house
        if (dp[i] != -1) return dp[i];
        return dp[i] = max(nums[i]+recur(i-2, nums, dp), recur(i-1, nums, dp));
    }

    int recur2(int i, vector<int>& nums, vector<int>& dp2) {
        if (i==1) return nums[1]; 
        if (i==0) return 0; // not including first house
        if (dp2[i] != -1) return dp2[i];
        // same logic but different calls and base case
        return dp2[i] = max(nums[i]+recur2(i-2, nums, dp2), recur2(i-1, nums, dp2));
    }

};
