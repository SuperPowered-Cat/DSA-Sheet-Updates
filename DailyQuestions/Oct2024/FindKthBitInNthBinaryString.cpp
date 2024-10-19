// leetcode 1545

class Solution {
public:
    string revNinv(string str) {
        string x = str;
        for (int i = 0; i < x.size(); i++) {
            if (x[i] == '0') x[i] = '1';
            else x[i] = '0';
        }
        reverse(x.begin(), x.end());
        return x;
    }

    string findString(int n) {
        if (n == 1) return "0";
        string str = findString(n-1);
        return str + "1" + revNinv(str);
    }

    char findKthBit(int n, int k) {
        string s = findString(n);
        return s[k-1];
    }
};
