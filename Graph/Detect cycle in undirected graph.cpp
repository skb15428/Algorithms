#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(V+E)
// Space Complexity - O(V)
bool findCycle_dfs(int src, int par, vector<int> adj[], vector<bool> &vis)
{
    vis[src] = 1;

    for (auto it : adj[src])
    {
        if (!vis[it])
        {
            if (findCycle_dfs(it, src, adj, vis))
            {
                return true;
            }
        }
        else
        {
            if (it != par)
            {
                return true;
            }
        }
    }
    return false;
}
// Time Complexity - O(V+E)
// Space Complexity - O(V)
bool findCycle_bfs(int src, vector<int> adj[], vector<bool> &vis)
{
    // {node,parent}
    queue<pair<int, int>> q;

    vis[src] = 1;
    q.push({src, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push({it, node});
            }
            else
            {
                if (parent != it)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    vector<bool> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            // if(findCycle_bfs(i,adj,vis)){
            //     return true;
            // }
            if (findCycle_dfs(i, -1, adj, vis))
            {
                return true;
            }
        }
    }
    return false;
}