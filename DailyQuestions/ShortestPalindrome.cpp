// leetcode 214

// IMPORTANT -> !!!!!! Read and understand KMP Algorithm !!!!!!


// ** Q: Shortest Palindrome **

// You are given a string s. You can convert s to a palindrome by adding characters in front of it.
// Return the shortest palindrome you can find by performing this transformation.?

// Example 1:
// Input: s = "aacecaaa"
// Output: "aaacecaaa"

// Example 2:
// Input: s = "abcd"
// Output: "dcbabcd"

// Constraints:
// 0 <= s.length <= 5 * 104
// s consists of lowercase English letters only.



// CODE ->

// my solution, takes O(n^2) time and isn't optimised
class Solution {

public:

    string largestPalindrome(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        if (s == s2) return s;
        return largestPalindrome(s.substr(0, s.length() - 1));
    } 

    string shortestPalindrome(string s1) {
        string s2 = largestPalindrome(s1);
        cout << s2;
        string s3 = "";
        for (int i = s2.size(); i < s1.size(); i++) {
            s3 = s3+s1[i];
        }
        string s4 = s3;
        reverse(s4.begin(), s4.end());
        return s4 + s2 + s3;
    }
};


// optimised code but not mine
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        
        int i = 0; //  i = 0 to n-1
        int j = n - 1; // j = n-1 to 0
        
        // Find the largest prefix palindrome
        while (j >= 0) {
            if (s[i] == s[j]) {
                i++;
            }
            j--;
        }
        
        // calculate leftover
        string leftover = s.substr(i); 
        
        // edge case
        if( leftover.size()==0 ){ return s; }

        string remreverse = leftover;
        reverse(remreverse.begin(), remreverse.end());

        // recursion yay
        return remreverse + shortestPalindrome(s.substr(0, i)) + leftover;
    }
};
