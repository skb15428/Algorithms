#include <bits/stdc++.h>
using namespace std;

// Time complexity - O(n*m)
// Space complexity - O(2*m)
bool solve_dp_SO(string s1, string s2, int n, int m)
{
    vector<vector<bool>> dp(2, vector<bool>(m + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i & 1][j] = true;
            }
            else if (i == 0)
            {
                dp[i & 1][j] = false;
            }
            else if (j == 0)
            {
                dp[i & 1][j] = true;
                for (int k = 0; k < i; k++)
                {
                    if (s1[k] != '*')
                    {
                        dp[i & 1][j] = false;
                        break;
                    }
                }
            }
            else
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i & 1][j] = dp[(i - 1) & 1][j - 1];
                }
                else
                {
                    if (s1[i - 1] == '?')
                    {
                        dp[i & 1][j] = dp[(i - 1) & 1][j - 1];
                    }
                    else if (s1[i - 1] == '*')
                    {
                        dp[i & 1][j] = dp[(i - 1) & 1][j] || dp[i & 1][j - 1];
                    }
                    else
                    {
                        dp[i & 1][j] = false;
                    }
                }
            }
        }
    }
    return dp[n & 1][m];
}

// Time complexity - O(n*m)
// Space complexity - O(n*m)
bool solve_dp(string s1, string s2, int n, int m)
{
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = true;
            }
            else if (i == 0)
            {
                dp[i][j] = false;
            }
            else if (j == 0)
            {
                dp[i][j] = true;
                for (int k = 0; k < i; k++)
                {
                    if (s1[k] != '*')
                    {
                        dp[i][j] = false;
                        break;
                    }
                }
            }
            else
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    if (s1[i - 1] == '?')
                    {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    else if (s1[i - 1] == '*')
                    {
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                        // dp[i][j] = false;
                        // for(int k=0;k<=j;k++){
                        //     if(dp[i-1][j-k]){
                        //         dp[i][j] = true;
                        //     }
                        // }
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }
            }
        }
    }
    return dp[n][m];
}

// For Recursion
// Time complexity - exponential
// Space complexity - O(n+m)
bool solve_rec_mem(string s1, string s2, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 && m == 0)
    {
        return true;
    }
    if (n <= 0)
    {
        return false;
    }

    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }

    if (m <= 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (s1[i] != '*')
            {
                return dp[n][m] = false;
            }
        }
        return dp[n][m] = true;
    }

    if (s1[n - 1] == s2[m - 1])
    {
        return dp[n][m] = solve_rec_mem(s1, s2, n - 1, m - 1, dp);
    }
    else
    {
        if (s1[n - 1] == '?')
        {
            return dp[n][m] = solve_rec_mem(s1, s2, n - 1, m - 1, dp);
        }
        else if (s1[n - 1] == '*')
        {
            return dp[n][m] = solve_rec_mem(s1, s2, n - 1, m, dp) || solve_rec_mem(s1, s2, n, m - 1, dp);
            // for(int i=0;i<=m;i++){
            //     if(dp[n][m] = solve_rec_mem(s1,s2,n-1,m-i,dp)){
            //         return true;
            //     }
            // }
            // return dp[n][m] = false;
        }
        else
        {
            return dp[n][m] = false;
        }
    }
}

// Problem link - https://leetcode.com/problems/wildcard-matching/description/
bool isMatch(string s, string p)
{
    int n = s.size();
    int m = p.size();

    // vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    // return solve_rec_mem(p,s,m,n,dp);

    // return solve_dp(p,s,m,n);

    return solve_dp_SO(p, s, m, n); // Reversed while sending strings
}