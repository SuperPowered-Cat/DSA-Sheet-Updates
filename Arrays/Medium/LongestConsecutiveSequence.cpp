class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        sort(nums.begin(), nums.end());
        int LastSmall = INT_MIN;
        int count = 0;
        int length = 1;

        for (int i = 0; i < n; i++) {
            if((nums[i] - 1) == LastSmall) {
                count++;
                LastSmall = nums[i];
            }
            else if(nums[i] != LastSmall) {
                count = 1;
                LastSmall = nums[i];
            }
            length = max(length, count);
        }
        return length;
    }
};
