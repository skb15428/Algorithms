#include <bits/stdc++.h>
using namespace std;

// Time complexity - O(n*n)
// Space Complexity - O(2*n)
int solve_dp_SO(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(2, vector<int>(n + 1, -1));

    for (int i = 1; i <= n; i++)
    {
        dp[n % 2][i] = triangle[n - 1][i - 1];
    }

    for (int i = n - 1; i > 0; i--)
    {
        for (int j = i; j > 0; j--)
        {
            dp[i % 2][j] = triangle[i - 1][j - 1] + min(dp[(i + 1) % 2][j], dp[(i + 1) % 2][j + 1]);
        }
    }
    return dp[1][1];
}

// Time complexity - O(n*n)
// Space Complexity - O(n*n)
int solve_dp(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    for (int i = 1; i <= n; i++)
    {
        dp[n][i] = triangle[n - 1][i - 1];
    }

    for (int i = n - 1; i > 0; i--)
    {
        for (int j = i; j > 0; j--)
        {
            dp[i][j] = triangle[i - 1][j - 1] + min(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    return dp[1][1];
}

// For Recurssive
// Time complexity - O(2^(n*n))
// Space Complexity - O(n)
int solve_rec_mem(vector<vector<int>> &triangle, int x, int y, int n, vector<vector<int>> &dp)
{
    if (x == n)
    {
        return 0;
    }
    if (dp[x][y] != -1)
    {
        return dp[x][y];
    }
    return dp[x][y] = triangle[x][y] + min(solve_rec_mem(triangle, x + 1, y, n, dp), solve_rec_mem(triangle, x + 1, y + 1, n, dp));
}
int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    // return solve_rec_mem(triangle,0,0,n,dp);

    // return solve_dp(triangle,n);
    return solve_dp_SO(triangle, n);
}