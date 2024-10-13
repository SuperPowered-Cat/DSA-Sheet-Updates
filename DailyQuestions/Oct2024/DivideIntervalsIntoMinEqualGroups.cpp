// leetcode 2406

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector <pair <int, int>> freq;
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector <int>, greater<int>> minheap;

        for (auto x : intervals) {
            int st = x[0];
            int ed = x[1];

            if (!minheap.empty() && minheap.top() < st) minheap.pop();

            minheap.push(ed);
        }

        return minheap.size();
    
    
    
    }
};
