// leetcode 3042
// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/?envType=daily-question&envId=2025-01-08

class Solution {
public:
    bool isPreAndSuff(string a, string b) {
        bool prefix = false, suffix = false;
        // prefix checking
        if(b.substr(0, a.size()) == a)  prefix = true;
        // suffix checking
        if(b.size() >= a.size()) {
            if (b.substr(b.size() - a.size()) == a) suffix = true;
        }

        return (prefix && suffix);
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for(int i = 0; i < words.size(); i++) {
            for (int j = i+1; j < words.size(); j++) {
                if (isPreAndSuff(words[i], words[j])) count++;
            }
        }
        return count;
    }
};
