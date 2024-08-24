class Solution {
public:
    long long reverse(long long x) {
        long long rev = 0;
        while (x != 0) {
            if (rev > INT_MAX/10 || rev*10 + x%10 >INT_MAX ) return 0;
            if (rev < INT_MIN/10 || rev*10 + x%10 <INT_MIN ) return 0;
            rev = 10*rev + x%10;
            x = x/10;
        }
    return rev;
    }
};
