// leetcode

// **Q: Differrent Ways To Add Parantheses**

// Given a string expression of numbers and operators, return all possible results from computing all the different 
// possible ways to group numbers and operators. You may return the answer in any order.

// The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does 
// not exceed 104.

// Example 1:
// Input: expression = "2-1-1"
// Output: [0,2]
// Explanation:
// ((2-1)-1) = 0 
// (2-(1-1)) = 2

// Example 2:
// Input: expression = "2*3-4*5"
// Output: [-34,-14,-10,-10,10]
// Explanation:
// (2*(3-(4*5))) = -34 
// ((2*3)-(4*5)) = -14 
// ((2*(3-4))*5) = -10 
// (2*((3-4)*5)) = -10 
// (((2*3)-4)*5) = 10
 
// Constraints:
// 1 <= expression.length <= 20
// expression consists of digits and the operator '+', '-', and '*'.
// All the integer values in the input expression are in the range [0, 99].
// The integer values in the input expression do not have a leading '-' or '+' denoting the sign.



// CODE ->

class Solution {
public:
    vector<int> diffWaysToCompute(string e) {
        vector <int> ans;
        
        for (int i = 0; i < e.size(); i++) {
            char ch = e[i];
            
            // dividing the string into seperate segments by the operands
            if (ch == '+' || ch == '-' || ch == '*') {
                
                // recursively breaking down by divide and conquer
                vector <int> subarr1 = diffWaysToCompute(e.substr(0, i));
                vector <int> subarr2 = diffWaysToCompute(e.substr(i+1));
                
                // checking for each element and storing 
                // ch is saved as the current operator
                for (int x: subarr1) {
                    for (int y : subarr2) {
                        if (ch == '+') ans.push_back(x+y);
                        else if (ch == '*') ans.push_back(x*y);
                        else if (ch == '-') ans.push_back(x-y);
                    }
                }
            }
        }

        // the default case for pushing back the elements when there's no operators
        // recursively, e becomes the sole number without any operator
        if (ans.empty()) ans.push_back(stoi(e));
        return ans;
    }
};
