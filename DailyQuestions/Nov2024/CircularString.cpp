// leetcode 2490

class Solution {
public:
    bool isCircularSentence(string sentence) {
        if(sentence[0] != sentence[sentence.size()-1]) return false;
        bool state = true;
        for(int i = 1; i < sentence.size()-1; i++) {
            if (sentence[i] == ' ') {
                if (char(sentence[i-1]) != char(sentence[i+1])) state = false;
            }
        }
        return state;
    }
};
