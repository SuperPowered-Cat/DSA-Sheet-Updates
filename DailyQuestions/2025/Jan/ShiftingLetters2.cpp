// leetcode 2381
// https://leetcode.com/problems/shifting-letters-ii/description/?envType=daily-question&envId=2025-01-05
class Solution {
public:

    // string backwards(int st, int end, string& x) {
    //     for (int i = st; i <= end; i++) {
    //         if (x[i] == 'a') x[i] = 'z';
    //         else x[i]--;
    //     }
    //     return x;
    // }

    // string forwards(int st, int end, string& x) {
    //     for (int i = st; i <= end; i++) {
    //         if (x[i] == 'z') x[i] = 'a';
    //         else x[i]++;
    //     }
    //     return x;
    // }

    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        // using difference array concept to find diff between ranges
        // then using prefix to add to those ranges and so it will be
        // less time consuming

        vector<int> diff (s.size() + 1, 0); // n+1 for marking end+1
        // will only update the start and end, and then simply prefix

        for (const vector<int>& shift : shifts) {
            int st = shift[0];
            int end = shift[1];
            int dir = shift[2];
            if (dir == 1) {
                diff[st]++;
                diff[end+1]--;
            }
            else {
                diff[st]--;
                diff[end+1]++;
            }
        }
        // now we have difference array, we will compute prefix
        // we will also add the values to the string in only 1 loop

        int shiftamt = 0; // prefix sum
        for (int i = 0; i < s.size(); i++) {
            shiftamt+=diff[i];
            s[i] = 'a' + (s[i] - 'a' + shiftamt % 26 + 26) % 26; 
        }

        return s;
    }
};
