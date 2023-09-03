#include <bits/stdc++.h>
using namespace std;

// Time complexity - O(n*m)
// Space complexity - O(2*m)
int solve_dp_SO(string s1, string s2, int n, int m)
{
    vector<vector<int>> dp(2, vector<int>(m + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (j == 0)
            {
                dp[i & 1][j] = i;
            }
            else if (i == 0)
            {
                dp[i & 1][j] = j;
            }
            else
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i & 1][j] = dp[(i - 1) & 1][j - 1];
                }
                else
                {
                    dp[i & 1][j] = 1 + min(dp[i & 1][j - 1], min(dp[(i - 1) & 1][j], dp[(i - 1) & 1][j - 1]));
                }
            }
        }
    }
    return dp[n & 1][m];
}

// Time complexity - O(n*m)
// Space complexity - O(n*m)
int solve_dp(string s1, string s2, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (j == 0)
            {
                dp[i][j] = i;
            }
            else if (i == 0)
            {
                dp[i][j] = j;
            }
            else
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
                }
            }
        }
    }
    return dp[n][m];
}

// For recursion
// Time complexity - O(2^(n*m))
// Space complexity - O(n+m)
int solve_rec_mem(string s1, string s2, int n, int m, vector<vector<int>> &dp)
{
    if (m == 0)
    {
        return n;
    }
    if (n == 0)
    {
        return m;
    }

    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }

    if (s1[n - 1] == s2[m - 1])
    {
        return dp[n][m] = solve_rec_mem(s1, s2, n - 1, m - 1, dp);
    }
    else
    {
        int insert = solve_rec_mem(s1, s2, n, m - 1, dp);
        int delete_ = solve_rec_mem(s1, s2, n - 1, m, dp);
        int replace = solve_rec_mem(s1, s2, n - 1, m - 1, dp);

        return dp[n][m] = 1 + min(insert, min(delete_, replace));
    }
}

// Problem link - https://leetcode.com/problems/edit-distance/description/
int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();

    // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    // return solve_rec_mem(word1,word2,n,m,dp);

    // return solve_dp(word1,word2,n,m);

    return solve_dp_SO(word1, word2, n, m);
}