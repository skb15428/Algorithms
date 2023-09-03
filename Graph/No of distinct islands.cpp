#include <bits/stdc++.h>
using namespace std;

// Time complexity - O(n*m*log(n*m))
// Space Complexity - O(n*m)
void dfs(int x, int y, int xi, int yi, int n, int m, vector<vector<int>> &grid, vector<vector<bool>> &vis, vector<pair<int, int>> &islands)
{
    if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y] || grid[x][y] != 1)
    {
        return;
    }

    vis[x][y] = 1;
    islands.push_back({x - xi, y - yi});

    // right
    dfs(x, y + 1, xi, yi, n, m, grid, vis, islands);
    // down
    dfs(x + 1, y, xi, yi, n, m, grid, vis, islands);
    // left
    dfs(x, y - 1, xi, yi, n, m, grid, vis, islands);
    // up
    dfs(x - 1, y, xi, yi, n, m, grid, vis, islands);
}
int countDistinctIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));

    set<vector<pair<int, int>>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && !vis[i][j])
            {
                vector<pair<int, int>> islands;
                dfs(i, j, i, j, n, m, grid, vis, islands);
                st.insert(islands);
            }
        }
    }
    return st.size();
}