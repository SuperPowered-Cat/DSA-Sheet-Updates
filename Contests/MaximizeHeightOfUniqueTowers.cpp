// leetcode Biweekly 140

// **Q: Maximize the Total Height of Unique Towers**


// CODE ->

class Solution {
public:
    long long maximumTotalSum(vector<int>& maxH) {
        int n = maxH.size(); 
        sort (maxH.begin(), maxH.end());
        // if (n > maxH[0]) return -1;
        long long ans = 0;
        int lastH = INT_MAX;
        for (int i = n - 1; i >= 0; --i) {
            int height = min(maxH[i], lastH - 1); 
            if (height <= 0) return -1;

            ans += height;  
            lastH = height;  
        }

        return ans; 
    }



};
