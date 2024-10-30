// leetcode 1671

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> lis(n, 1);
        vector<int> lds(n, 1);

        // longest increasing subsequence
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (nums[j] > nums[i]) lis[j] = max(lis[j], lis[i] + 1);
            }
        }

        // longest decreasing subsequence
        for (int i = n-1; i>=0; i--) {
            for (int j = i-1; j >= 0; j--) {
                if (nums[j] > nums[i]) lds[j] = max(lds[j], lds[i] + 1);
            }
        }

        // now for each i we have longest increasing and decreasing subsequence
        // this means that now we can just take each element i as a peak
        int minRem = INT_MAX;
        // by setting this number as max we can set up and then iterate through it,
        // getting the no. of elements needed to be removed and then finding min 

        // the challenge is finding out how many elements to remove
        
        // for the element to be peak, we need to make sure either side is  
        // strictly increasing or decreasing. this can be done using lis and lds

        // lis is the longest increasing subsequence. and on the left side there 
        // are i + 1 elements (0 based indexing)

        // dis is the longest decreasing subsq, and right side there are n-i 
        // elements

        // so no of elements to remove on left side = (i+1) - LIS[i]
        // and no of elements to remove on right side = (N-i) - LDS[i]

        // so remove elements count = (i + 1 - LIS[i]) + (N - i - LDS[i]
        // -> count = N + 1 - LIS[i] - LDS[i]

        // WE DO THIS FOR EACH ELEMENT ADN THERES THE ANSWER!

        for (int i = 0; i < n; i++) {
            if ((lis[i] > 1) && (lds[i] > 1)) {
                int count = n + 1 - lis[i] - lds[i];
                minRem = min(minRem, count);
            }
        }

        return minRem;
    }
};
