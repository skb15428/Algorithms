#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(N*M)
// Space Complexity - O(N*M)
int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    if (n == 0)
        return 0;
    int m = grid[0].size();

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    // {row,col,time}
    queue<vector<int>> q;

    int countVis1 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                vis[i][j] = 1;
                q.push({i, j, 0});
            }
            else if (grid[i][j] == 1)
            {
                countVis1++;
            }
        }
    }

    int ans = 0;
    while (!q.empty())
    {
        vector<int> temp = q.front();
        q.pop();

        ans = max(ans, temp[2]);

        for (int i = 0; i < 4; i++)
        {
            int x = temp[0] + dx[i];
            int y = temp[1] + dy[i];

            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 && !vis[x][y])
            {
                vis[x][y] = 1;
                q.push({x, y, temp[2] + 1});
                countVis1--;
            }
        }
    }

    return countVis1 == 0 ? ans : -1;
}