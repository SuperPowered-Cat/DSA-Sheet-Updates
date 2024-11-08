// leetcode 547

class Solution {
public:
    void dfs(int node, vector<bool>& visited, const vector<vector<int>>& adjList) {
        visited[node] = true;
        for (auto newnode : adjList[node]) {
            if (!visited[newnode]) dfs(newnode, visited, adjList);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adjList(isConnected.size());

        // convert matrix to adjacency list
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected.size(); j++) {
                if (isConnected[i][j] == 1) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<bool> visited(isConnected.size(), 0);
        int ans = 0;
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i]) {
                ans++;
                dfs(i, visited, adjList);
            }
        }

        return ans;
    }
};
