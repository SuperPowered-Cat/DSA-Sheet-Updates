//leetcode 1497

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> comp(k, 0);
        for (int x : arr) {
            int rem = x%k;
            if (rem<0) rem+=k;
            comp[rem]++;
        }

        if (comp[0] % 2 != 0) return false;

        for (int i = 1; i <= k/2; i++) {
            if (comp[i] != comp[k-i]) return false;
        }
        
        return true;
    }

};
