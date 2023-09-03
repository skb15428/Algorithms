#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(N*E)
// Space Complexity - O(N)
void dfs(int src, vector<int> adj[], vector<bool> &vis, stack<int> &st)
{
    vis[src] = 1;
    for (int it : adj[src])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, st);
        }
    }
    st.push(src);
}

// Problem link - https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// This algorithm is only valid in DAG (Directed acyclic graph)
// Defination - If there is a edge between u and v, u appears before v in the linear ordering.
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<bool> vis(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, st);
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}