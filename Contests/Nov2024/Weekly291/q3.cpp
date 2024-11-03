class Solution {
public:
    typedef tuple<int, int, int, bool> State; // timee x y and STATE
    const vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        // 3d matrix 
        vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));
        
        
        // Min heap: {time, x, y, isNextMoveTwo}
        priority_queue<State, vector<State>, greater<State>> pq;
        
        
        dist[0][0][0] = 0;
        pq.push({0, 0, 0, false});
        
        while (!pq.empty()) {
            auto [currTime, x, y, nextState] = pq.top();
            pq.pop();
            
            if (x == n-1 && y == m-1) return currTime;
            
            // If this state has been improved upon, skip it
            if (currTime > dist[x][y][nextState]) continue;
            
            for (const auto& d : dir) {
                int newx = x + d.first;
                int newy = y + d.second;
                
                if (newx >= 0 && newy >= 0 && newx < n && newy < m) {
                    int moveCost = nextState ? 2 : 1;
                    int newTime = max(currTime + moveCost, moveTime[newx][newy] + moveCost);
                    bool updatedState = !nextState;
                    
                    if (newTime < dist[newx][newy][updatedState]) {
                        dist[newx][newy][updatedState] = newTime;
                        pq.push({newTime, newx, newy, updatedState});
                    }
                }
            }
        }
        return -1;
    }
};
