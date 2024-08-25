class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = -1;

        //put i pointer to first zero.
        for (int j = 0; j<nums.size(); j++) {
            if (nums[j] == 0) {
                i = j;
                break;
            }
        }

        //EDGE CASE - NO ZEROS.
        if (i == -1) return;
        

        for (int j = i+1; j<nums.size(); j++) {
            if (nums[j] != 0) {
                swap(nums[j], nums[i]);
                i++;
            }
        }
    }

    // BRUTEFORCE (BUT EZ) METHOD
    // void moveZeroes(vector<int>& nums) {
    //     vector<int> arr2;
    //     int n = nums.size();
    //     for (int i = 0; i<n; i++) if (nums[i] !=0 ) arr2.push_back(nums[i]);
    //     int nzSize = arr2.size();
    //     for (int i = 0; i<nzSize; i++) nums[i] = arr2[i];
    //     for (int i = nzSize; i<n; i++) nums[i] = 0;
    // }
};
