class Solution {
public:
    bool isPalindrome(long long x) {
        if (x < 0) return false;
        long long temp = x;
        long long rev = 0;
        while (temp != 0) {
            if (rev > INT_MAX/10 || rev*10 + x%10 >INT_MAX ) return 0;
            if (rev < INT_MIN/10 || rev*10 + x%10 <INT_MIN ) return 0;
            rev = 10*rev + temp%10;
            temp = temp/10;
        }
    return (rev==x);
    }
};
