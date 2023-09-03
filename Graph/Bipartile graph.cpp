#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(N+E)
// Space complexity - O(N)
bool isBipartile_dfs(int n, vector<vector<int>> &graph, vector<int> &col)
{
    for (int it : graph[n])
    {
        if (col[it] == -1)
        {
            col[it] = col[n] == 0 ? 1 : 0;
            if (!isBipartile_dfs(it, graph, col))
            {
                return false;
            }
        }
        else
        {
            if (col[n] == col[it])
            {
                return false;
            }
        }
    }
    return true;
}

// Time Complexity - O(N+E)
// Space complexity - O(N)
bool isBipartile_bfs(int n, vector<vector<int>> &graph, vector<int> &col)
{
    queue<int> q;
    q.push(n);

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        for (int it : graph[temp])
        {
            if (col[it] == -1)
            {
                col[it] = col[temp] == 0 ? 1 : 0;
                q.push(it);
            }
            else
            {
                if (col[temp] == col[it])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

// Problem link - https://leetcode.com/problems/is-graph-bipartite/description/
bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> col(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (col[i] == -1)
        {
            col[i] = 0;

            // For bfs
            if (!isBipartile_bfs(i, graph, col))
            {
                return false;
            }

            // For dfs
            // if(!isBipartile_dfs(i,graph,col)){
            //     return false;
            // }
        }
    }
    return true;
}