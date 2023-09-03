#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(V+E)
// Space Complexity - O(V)
void dfsFun(int n, vector<int> adj[], int vis[], vector<int> &dfs)
{
    vis[n] = 1;
    dfs.push_back(n);

    for (auto it : adj[n])
    {
        if (!vis[it])
        {
            dfsFun(it, adj, vis, dfs);
        }
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    int vis[V] = {0};
    vector<int> dfs;

    dfsFun(0, adj, vis, dfs);
    return dfs;
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

    vector<int> dfs = dfsOfGraph(n, adj);

    for (auto x : dfs)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}