// leetcode 386

// **Q: Lexicographical Numbers**

// Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
// You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

// Example 1:
// Input: n = 13
// Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]

// Example 2:
// Input: n = 2
// Output: [1,2]
 
// Constraints:
// 1 <= n <= 5 * 104

  
// CODE ->

class Solution {
public:

    // this code works but its not optimal
    // time and space complexity should be reduced
    vector<int> lexicalOrder(int n) {
        vector <string> strans;
        for (int i = 1; i <= n; i++) {
            string num = to_string(i);
            strans.push_back(num);
        }
        sort(strans.begin(), strans.end());
        vector<int> ans;
        for (string c : strans) {
            ans.push_back(stoi(c));
        } 
        return ans;
    }
};
