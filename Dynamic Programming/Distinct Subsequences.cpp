#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(n*m)
// Space Complexity - O(2*m)
int solve_dp_SO(string s, string t, int n, int m)
{
    int mod = 1e9 + 7;
    vector<vector<int>> dp(2, vector<int>(m + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (j == 0)
            {
                dp[i & 1][j] = 1;
            }
            else if (i == 0)
            {
                dp[i & 1][j] = 0;
            }
            else
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i & 1][j] = dp[(i - 1) & 1][j - 1] % mod + dp[(i - 1) & 1][j] % mod;
                }
                else
                {
                    dp[i & 1][j] = dp[(i - 1) & 1][j] % mod;
                }
            }
        }
    }
    return dp[n & 1][m] % mod;
}

// Time Complexity - O(n*m)
// Space Complexity - O(n*m)
int solve_dp(string s, string t, int n, int m)
{
    int mod = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 1;
            }
            else if (i == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] % mod + dp[i - 1][j] % mod;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] % mod;
                }
            }
        }
    }
    return dp[n][m] % mod;
}

// For Recursion
// Time Complexity - O(2^(n*m))
// Space Complexity - O(n+m)
int solve_rec_mem(string s, string t, int n, int m, vector<vector<int>> &dp)
{
    if (m == 0)
        return 1;
    if (n == 0)
        return 0;

    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }

    if (s[n - 1] == t[m - 1])
    {
        return dp[n][m] = solve_rec_mem(s, t, n - 1, m - 1, dp) + solve_rec_mem(s, t, n - 1, m, dp);
    }
    else
    {
        return dp[n][m] = solve_rec_mem(s, t, n - 1, m, dp);
    }
}

// Problem Link - https://leetcode.com/problems/distinct-subsequences/description/
int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    // return solve_rec_mem(s,t,n,m,dp);
    // return solve_dp(s,t,n,m);
    return solve_dp_SO(s, t, n, m);
}