#include <bits/stdc++.h>
using namespace std;

// Time complexity - O(n*m)
// Space Complexity - O(2*m)
int solve_dp_SO(vector<vector<int>> &mat, int n, int m)
{
    vector<vector<int>> dp(2, vector<int>(m + 2, 1e9));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1)
            {
                dp[i % 2][j] = mat[i - 1][j - 1];
            }
            else
            {
                dp[i % 2][j] = mat[i - 1][j - 1] + min(dp[(i - 1) % 2][j - 1], min(dp[(i - 1) % 2][j], dp[(i - 1) % 2][j + 1]));
            }
        }
    }
    return *min_element(dp[n % 2].begin(), dp[n % 2].end());
}

// Time complexity - O(n*m)
// Space Complexity - O(n*m)
int solve_dp(vector<vector<int>> &mat, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 2, 1e9));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1)
            {
                dp[i][j] = mat[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = mat[i - 1][j - 1] + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1]));
            }
        }
    }
    return *min_element(dp[n].begin(), dp[n].end());
}

// For Recurssion
// Time complexity - O(3*(n*m))
// Space Complexity - O(n)
int solve_rec_mem(vector<vector<int>> &mat, int x, int y, int m, vector<vector<int>> &dp)
{
    if (y <= 0 || y > m)
        return 1e9;

    if (x == 1)
    {
        return mat[x - 1][y - 1];
    }

    if (dp[x][y] != 1e9)
        return dp[x][y];

    return dp[x][y] = mat[x - 1][y - 1] + min(solve_rec_mem(mat, x - 1, y - 1, m, dp), min(solve_rec_mem(mat, x - 1, y, m, dp), solve_rec_mem(mat, x - 1, y + 1, m, dp)));
}
int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    if (n == 0)
        return INT_MAX;
    int m = matrix[0].size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));

    // int mini = INT_MAX;
    // for(int i=1;i<=m;i++){
    // mini = min(mini,solve_rec_mem(matrix,n,i,m,dp));
    // }
    // return mini;

    // return solve_dp(matrix,n,m);

    return solve_dp_SO(matrix, n, m);
}