// leetcode 3163


class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int count = 1;

        for (int i = 1; i <= word.size(); i++) {
            if (word[i] == word[i-1] && count < 9) count++;
            else {
                ans+= to_string(count) + word[i-1];
                count = 1;
            }
        }

        return ans;
    }
};
