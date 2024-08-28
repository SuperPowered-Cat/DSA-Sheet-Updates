class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // bruteforce (decent  method)
        // time complexity = O(n+(n/2))
        // vector<int> pos, neg;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i]>=0) pos.push_back(nums[i]);
        //     else neg.push_back(nums[i]);
        // }
        // for (int i = 0; i < nums.size()/2; i++) {
        //     nums[2*i] = pos[i];
        //     nums[2*i+1] = neg[i];
        // }
        // return nums;

        //in only SINGLE PASS - time O(n)

        int pos = 0, neg = 1; //first +ve at 0th index, first -ve at 1st
        vector<int> newarr(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++ ) {
            
            if(nums[i]>=0) {
                newarr[pos] = nums[i];
                pos+=2;
            }
            else {
                newarr[neg] = nums[i];
                neg+=2;
            }
        }
        return newarr;
    }
};
