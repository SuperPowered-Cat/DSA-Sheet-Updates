// leetcode 2601

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int maximum = *max_element(nums.begin(), nums.end());
        // sieve of some greek guy
        vector<bool> sieve (maximum+1, true);
        for (int i = 0; i < sieve.size(); i++) {
            if (i == 0 || i == 1) sieve[i] = false;
            if (sieve[i] == true) {
                int temp = i*i;
                while (temp<=maximum) {
                    sieve[temp] = false;
                    temp+=i;
                }
            }
        }
        int minimum = 1;
        int i = 0;
        while (i < nums.size()) {
            int diff = nums[i] - minimum;
            if (diff < 0) return false;
            if (diff == 0 || sieve[diff] == 1) {
                i++;
                minimum++;
            } 
            else minimum++;
        }
        return true;
    }
};
