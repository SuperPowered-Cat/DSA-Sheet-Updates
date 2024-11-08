#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<bool> &visited, const vector<vector<int>> adjlist)
{
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < adjlist.size(); i++)
    {
        if (!visited[i])
            dfs(i, visited, adjlist);
    }
}

int main()
{
    int n = 6; // Number of nodes
    vector<vector<int>> adj(6);

    // Example graph edges (for an undirected graph)
    adj[0] = {};
    adj[1] = {2, 5};
    adj[2] = {1, 3, 5};
    adj[3] = {2, 4, 5};
    adj[4] = {3, 5};
    adj[5] = {1, 2, 3, 4};

    vector<bool> visited(n, false);

    cout << "DFS Traversal: ";
    dfs(0, visited, adj);

    return 0;
}
