//leetcode 1813


class Solution {
public:
    vector<string> split(string s) {
        vector<string> words;
        string x = "";
        for (char c : s) {
            if (c == ' ') {
                if (!x.empty()) {
                    words.push_back(x);
                    x.clear();
                }
            }
            else {
                x+=c;
            }
        }
        
        if (!x.empty()) words.push_back(x);
        return words;
    }
    bool areSentencesSimilar(string s1, string s2) {
        vector<string> w1 = split(s1);
        vector<string> w2 = split(s2);

        if (w1.size() < w2.size()) swap (w1, w2);

        // double pointer approach
        int i = 0, j = 0; // start and end pointers
        int n1 = w1.size(), n2 = w2.size(); 

        while (i < n2 && w1[i] == w2[i]) i++; 
        while (j < n2 && w1[n1 - j - 1] == w2[n2 - j - 1]) j++;
        return (i+j >= n2);
    }
};
