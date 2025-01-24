// leetcode 802
// https://leetcode.com/problems/find-eventual-safe-states/description/?envType=daily-question&envId=2025-01-24

class Solution {
public:

    // modified func of dfs to tell whether node is unsafe or not
    bool unsafeDfs(int node, vector<bool>& visited, vector<bool> &inStack, vector<vector<int>>& graph) {
        // back edge exists
        if(inStack[node]) return true; // unsafe node
        if (visited[node]) return false; // no back edge and visited

        // normal dfs with inStack addition
        visited[node] = true;
        inStack[node] = true;

        for (int n : graph[node]) { // checking all neighbours of node
            if (unsafeDfs(n, visited, inStack, graph)) return true; 
            // if dfs of neighbour is true, then n is also unsafe
            // because its all in the same cycle
        }

        // if its not true, then the node will be removed from stack
        inStack[node] = false;
        return false; // safe node
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n), inStack(n);
        
        for (int i = 0; i < n; i++) unsafeDfs(i, visited, inStack, graph);

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            // all the nodes from 0 to n, if they are not in the stack
            if (!inStack[i]) ans.push_back(i);
        }

        return ans;
    }
};
