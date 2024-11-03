class Solution {
public:

    // standard djikstra algo
    typedef pair<int, pair<int, int>> piii;

    const vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        
        // distance set to max
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX)); 

        // min heap
        priority_queue<piii, vector<piii>, greater<piii>> pq;
        dist[0][0] = 0;
        pq.push({dist[0][0], {0, 0}});
        while (!pq.empty()) {
            int currTime = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            
            if (x == n-1 && y == m-1) return currTime;

            for (const auto& d : dir) {
                int newx = x + d.first;
                int newy = y + d.second;

                if(newx >= 0 && newy >= 0 && newx < n && newy < m) {
                    int newTime = max(currTime + 1, moveTime[newx][newy] + 1);

                    if (newTime < dist[newx][newy]) {
                        dist[newx][newy] = newTime;
                        pq.push({newTime, {newx, newy}});
                    }  
                }
            }
        }
        return -1;
    }
};
