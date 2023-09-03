#include <bits/stdc++.h>
using namespace std;

bool findCycle_topoSort_bfs(int V, vector<int> adj[])
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

    int cnt = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;

        for (int it : adj[node])
        {
            inDegree[it]--;
            if (inDegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    return cnt == V;
}