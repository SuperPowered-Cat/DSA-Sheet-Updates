class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // ez method 
        // next_permutation(nums.begin(), nums.end());
        
        // BREAKPOINT TEST
        // array will be in decreasing order until the breakpoint
        // so can find the breakpoint and then swap element of the break-
        // -point 
        int br = -1;
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                br = i;
                break;
            }
        }

        if (br == -1) { 
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n-1; i > br; i--) {
            if (nums[i]>nums[br]) {
                swap(nums[i], nums[br]);
                break;
            }
        }

        // to make sure that after the next greatest element is swapped,
        // rest elments are in lexical order.
        reverse(nums.begin()+br+1, nums.end());


    }
};
