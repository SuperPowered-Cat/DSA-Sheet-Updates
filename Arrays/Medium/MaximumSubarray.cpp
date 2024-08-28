class Solution {
public:
    int maxSubArray(vector<int>& nums) {

      // Kadane algorithm.
        int max = INT_MIN; 
        int sum = 0;
        for (int i= 0; i<nums.size(); i++) {
            sum+=nums[i];
            if (max < sum) max = sum;
            if (sum < 0) sum = 0;
        }
    return max;
    }

    // int maxSubArray(vector<int>& nums) {
    
    //   // for returning the max array;
    //   // Kadane algorithm.
    //     int max = INT_MIN; 
    //     int sum = 0;
    //     int start = 0;
    //     int fstart = -1, intfend = -1;
    //     for (int i= 0; i<nums.size(); i++) {
    //         if (sum===0) start = i;
    //         sum+=nums[i];
    //         if (max < sum){
    //             max = sum;
    //             fstart = start;
    //             fend = i;
    //         }
    //         if (sum < 0) sum = 0;
    //     }
    // return max;
    // }
};
