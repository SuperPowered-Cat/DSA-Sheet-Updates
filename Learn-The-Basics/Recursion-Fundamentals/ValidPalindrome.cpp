class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length()>=2*10e5) return false;
        string newstr = "";
        for (char c : s) {
            if (isalnum(c)) newstr+=tolower(c);
        }
        return PalindromeHelper(newstr, 0, newstr.length()-1);
    }

    bool PalindromeHelper(const string& s, int l, int r) {
        if (l>=r) return true;
        if (s[l] != s[r]) return false;
        return PalindromeHelper(s, l+1, r-1);
    }
};
