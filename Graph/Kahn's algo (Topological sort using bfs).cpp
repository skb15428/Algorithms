#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(N*E)
// Space Complexity - O(N)
// Problem link - https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// This algorithm is only valid in DAG (Directed acyclic graph)
// Defination - If there is a edge between u and v, u appears before v in the linear ordering.
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> inDegree(V, 0);

    for (int i = 0; i < V; i++)
    {
        for (int it : adj[i])
        {
            inDegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> ans;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (int it : adj[node])
        {
            inDegree[it]--;
            if (inDegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    return ans;
}