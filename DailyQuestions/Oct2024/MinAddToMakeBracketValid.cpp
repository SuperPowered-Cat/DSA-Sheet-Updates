//leetcode 921

class Solution {
public:
    int minAddToMakeValid(string s) {

        // variable tracking approach, O(n) time O(1) space
        int close = 0, left = 0;
        for (char c : s) {
            if (c == '(') close++;
            else {
                if (close>0) close--;
                else left++;
            }
        }
        return close + left;

        // stack approach - O(n) time O(n) space
        stack <char> st;
        for (int i = 0; i < s.size(); i++) {
            if(st.empty()) st.push(s[i]);
            else {
                if (st.top() == '(' && s[i] == ')') st.pop();
                else st.push(s[i]);
            }
        }
        return st.size();

        
    }
};
