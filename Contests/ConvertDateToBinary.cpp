// **Q: Convert Date to Binary**

// You are given a string date representing a Gregorian calendar date in the yyyy-mm-dd format.
// date can be written in its binary representation obtained by converting year, month, and day to their binary 
// representations without any leading zeroes and writing them down in year-month-day format.
// Return the binary representation of date.

// Example 1:
// Input: date = "2080-02-29"
// Output: "100000100000-10-11101"
// Explanation:
// 100000100000, 10, and 11101 are the binary representations of 2080, 02, and 29 respectively.

// Example 2:
// Input: date = "1900-01-01"
// Output: "11101101100-1-1"
// Explanation:
// 11101101100, 1, and 1 are the binary representations of 1900, 1, and 1 respectively.

// Constraints:
// date.length == 10
// date[4] == date[7] == '-', and all other date[i]'s are digits.
// The input is generated such that date represents a valid Gregorian calendar date between Jan 1st, 1900 and Dec 31st, 
// 2100 (both inclusive).


// CODE -> 
class Solution {
public:
    string convertDateToBinary(string d) {
        // yyyy-mm-dd
        // 0123456789
        string yearS = d.substr(0, 4);
        string monthS = d.substr(5, 2); 
        string dateS = d.substr(8, 2);
        // cout << year;
        // cout << year << endl << month << endl << date << endl;
        
        int year = stoi(yearS);
        int month = stoi(monthS);
        int date = stoi(dateS);

        string biny = bin(year);
        string binm = bin(month);
        string bind = bin(date);

        biny = trim(biny);
        binm = trim(binm);
        bind = trim(bind);

        return biny + "-" + binm + "-" + bind;
    }

    string bin(int x) {
        bitset<32> binary(x);
        return binary.to_string();
    }
    string trim(string s) {
        size_t pos = s.find('1');
        if (pos != string::npos) {
            return s.substr(pos); 
        }
        return "0"; // base condition
    }
};
