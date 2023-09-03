#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(N*E)
// Space Complexity - O(N)
bool dfs(int n, vector<int> adj[], vector<bool> &vis, vector<bool> &pathVis)
{
    vis[n] = 1;
    pathVis[n] = 1;

    for (int node : adj[n])
    {
        if (!vis[node])
        {
            if (dfs(node, adj, vis, pathVis))
            {
                return true;
            }
        }
        else
        {
            if (pathVis[node])
            {
                return true;
            }
        }
    }
    pathVis[n] = 0;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> vis(V, false);
    vector<bool> pathVis(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis, pathVis))
            {
                return true;
            }
        }
    }
    return false;
}