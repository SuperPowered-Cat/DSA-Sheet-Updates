// ** Question: Find the Key of Numbers **

// You are given three positive integers num1, num2, and num3.

// The key of num1, num2, and num3 is defined as a four-digit number such that:

// Initially, if any number has less than four digits, it is padded with leading zeros.
// The ith digit (1 <= i <= 4) of the key is generated by taking the smallest digit among the ith digits of num1, num2, and num3.
// Return the key of the three numbers without leading zeros (if any).

 

// Example 1:

// Input: num1 = 1, num2 = 10, num3 = 1000

// Output: 0

// Explanation:

// On padding, num1 becomes "0001", num2 becomes "0010", and num3 remains "1000".

// The 1st digit of the key is min(0, 0, 1).
// The 2nd digit of the key is min(0, 0, 0).
// The 3rd digit of the key is min(0, 1, 0).
// The 4th digit of the key is min(1, 0, 0).
// Hence, the key is "0000", i.e. 0.

// Example 2:

// Input: num1 = 987, num2 = 879, num3 = 798

// Output: 777

// Example 3:

// Input: num1 = 1, num2 = 2, num3 = 3

// Output: 1

// Constraints:

// 1 <= num1, num2, num3 <= 9999


class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string n1 = to_string(num1);
        string n2 = to_string(num2);
        string n3 = to_string(num3);
        
        string pn1 = pad(n1);
        string pn2 = pad(n2);
        string pn3 = pad(n3);

        char knum1 = min(min(pn1[0], pn2[0]), pn3[0]);
        char knum2 = min(min(pn1[1], pn2[1]), pn3[1]);
        char knum3 = min(min(pn1[2], pn2[2]), pn3[2]);
        char knum4 = min(min(pn1[3], pn2[3]), pn3[3]);

        string key = string {knum1, knum2, knum3, knum4};

        return std::stoi(key);

    }

    string pad(string x) {
        int maxlen = 4;
        int zerocount = maxlen - x.length();
        if (zerocount > 0) {
            string padx = string(zerocount, '0') + x;
            return padx;
        }
        return x;
    }

    
};