class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {


        vector<vector<int>> graph(n);
        vector<int> inDegree(n, 0);
        for (const auto& inv : invocations) {
            graph[inv[0]].push_back(inv[1]);
            inDegree[inv[1]]++;
        }

        unordered_set<int> sus;
        vector<bool> visited(n, false);
        
        dfs(k, graph, sus, visited);

        vector<int> res;
        bool validate = true;
        for (int i = 0; i < n; i++) {
            if (sus.count(i) == 0) {
                for (int nbr : graph[i]) {
                    if (sus.count(nbr) > 0) {
                        validate = false;
                        break;
                    }
                }
                if (!validate) break;
                res.push_back(i);
            }
        }

        if (!validate) {
            res.clear();
            for (int i = 0; i < n; i++) {
                res.push_back(i);
            }
        }

        return res;
    }

private:
    void dfs(int node, const vector<vector<int>>& graph, unordered_set<int>& sus, vector<bool>& visited) {
        visited[node] = true;
        sus.insert(node);
        for (int nbr : graph[node]) {
            if (!visited[nbr]) {
                dfs(nbr, graph, sus, visited);
            }
        }
    }
};
