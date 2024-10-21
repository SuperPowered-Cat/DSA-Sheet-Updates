// leetcode 1593

class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> visited;
        // using backtracking approach
        // set for keeping track of visited elements
        return backtracking(0, s, visited);
    }

    int backtracking(int start, const string& s, unordered_set<string>& visited) {
        if (start == s.size()) return 0;
        int maximum = 0;
        // i is the end of the substring
        for (int i = start+1; i <= s.size(); ++i) {
            string small = s.substr(start, i-start); // no of ele after start
            if (visited.find(small) == visited.end()) {
                visited.insert(small); 
                // recursively moving to more substrings
                maximum = max(maximum, 1 + backtracking(i, s, visited));
                visited.erase(small); // backtracking - removing substring
            }
        }
        return maximum;
    }
};
