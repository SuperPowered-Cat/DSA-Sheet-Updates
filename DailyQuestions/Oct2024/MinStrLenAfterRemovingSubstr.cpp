// leetcode 2696

class Solution {
public:
    int minLength(string s) {
        
        // bruteforce - finding all strings and deleting
        // while (s.find("AB") != -1 || s.find("CD") != -1) {
        //     if (s.find("AB") != -1) s.erase(s.find("AB"), 2);
        //     else if (s.find("CD") != -1) s.erase(s.find("CD"), 2);
        // }
        // return s.size();

        // optimised - using stack (similar to paranthesis question)
        stack <char> st;
        for (int i = 0; i < s.size(); i++) {
            char currChar = s[i];
            if (st.empty()) {
                st.push(currChar);
                continue;
            }
            if (currChar == 'B' && st.top() == 'A') st.pop();
            else if(currChar == 'D' && st.top() == 'C') st.pop();
            else st.push(currChar);
        }
        return st.size();
    }
};
