#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(m*n)
// Space Complexity - O(2*n)
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    if (m == 0)
        return 0;
    int n = grid[0].size();

    vector<vector<int>> dp(2, vector<int>(n + 1, INT_MAX));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
            {
                dp[i % 2][j] = grid[i - 1][j - 1];
            }
            else
            {
                dp[i % 2][j] = min(dp[(i - 1) % 2][j], dp[i % 2][j - 1]) + grid[i - 1][j - 1];
            }
        }
    }

    return dp[m % 2][n];
}

int main()
{
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}};
    cout << minPathSum(grid) << endl;
}