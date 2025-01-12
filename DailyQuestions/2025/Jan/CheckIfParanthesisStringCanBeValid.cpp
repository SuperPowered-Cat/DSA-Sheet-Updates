// leetcode 2116
// 

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int size = s.size();
        if (size%2 != 0) return false;
        // dynamically checking lowest and highest of all
        int low1 = 0, high1 = 0;

        // first pass, checking for the (
        // here if ) is encountered then low decreased because cut by ) 
        for (int i = 0; i < s.size(); i++) {
            // treating unlocked as special * which can be both '(' & ')'
            if (locked[i] == '0') {
                low1 = max(0, low1-1);
                high1++;
            }
            // otherwise chekcing for locked
            else {
                // if open bracker
                if (s[i] == '(') {
                    low1++;
                    high1++;
                }
                else { // if closed, then open also decreased 
                    low1 = max(0, low1-1); // low also decreased
                    high1--;
                }
            }
            if (high1 < 0) return false; // less no of ( than )
        }

        int low2 = 0, high2 = 0; // second variable pass
        // here in 2nd pass if ( encountered then low increased
        // because minimum required increased
        for (int i = s.size() - 1; i>= 0; i--) {
            if (locked[i] == '0') {
                low2 = max(low2-1, 0);
                high2++;
            }
            else {
                if (s[i] == ')') {
                    low2++;
                    high2++;
                }
                else {
                    low2 = max(0, low2-1);
                    high2--;
                }
            }
            if (high2 < 0) return false;
        }
        
        return low2 == 0;
    }
};
