// leetcode 1106

class Solution {
public:

    char evaluateExpr(char op, string expr) {
        if (op == '&') {
            for (char x : expr) {
                if (x == 'f') return 'f';
            }
            return 't';
        }
        else if(op == '|') {
            for (char x : expr) {
                if (x == 't') return 't';
            }
            return 'f';
        }
        else {
            if (expr[0] == 't') return 'f';
            return 't';
        }
    }

    bool parseBoolExpr(string expression) {
        stack<char> st;
        for (char x : expression) {
            if (x != ',') st.push(x);
            string temp = "";
            if (x == ')') {
                while (!st.empty() && st.top() != '(') {
                    char t = st.top();
                    st.pop();
                    if (t != ',' && t != ')') {
                        temp += t;
                    }
                }
                st.pop(); // pop the '('
                char op = st.top();
                st.pop(); // pop the operator
                char stPush = evaluateExpr(op, temp);
                st.push(stPush); // push the result of the sub-expression
            }
        }

        return st.top() == 't'; // final result of the expression
    }
};
