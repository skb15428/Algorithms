#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(V+E)
// Space Complexity - O(V)
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    bool vis[V] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);

    vector<int> bfs;

    while (!q.empty())
    {
        int n = q.front();
        q.pop();

        bfs.push_back(n);

        for (auto it : adj[n])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main()
{
    int n;
    cin >> n;

    vector<int> adj[n];
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> bfs = bfsOfGraph(n, adj);

    for (auto x : bfs)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}