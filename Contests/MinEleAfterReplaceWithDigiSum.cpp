// leetcode biweekly contest 140
// **Q: Minimum Element After Replacement With Digit Sum**

// CODE ->

class Solution {
public:

    int digiSum(int n) {
        int sum = 0;
        while (n>0) {
            sum = sum + n%10;
            n= n/10;
        }
        return sum;
    }

    int minElement(vector<int>& nums) {
        vector <int> ans;
        for (int x : nums) ans.push_back(digiSum(x));
        sort (ans.begin(), ans.end());
        return ans[0];
    }
};
