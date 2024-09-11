// Leetcode 461

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        long xorval = x^y;
        while (xorval!=0) {
            if (xorval & 1) // bitwise AND 
                count++;
            xorval = xorval>>1;
        }
        return count;
    }
};
