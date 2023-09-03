#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(n*n)
// Space Complexity - O(n)
int solve_dp_SO(int n, int len)
{
    vector<vector<int>> dp(2, vector<int>(len + 1));
    vector<int> prev(len + 1), cur(len + 1);

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= len; j++)
        {
            if (i < 2)
            {
                cur[j] = i;
            }
            else
            {
                if (j >= i)
                {
                    cur[j] = max(i * cur[j - i], prev[j]);
                }
                else
                {
                    cur[j] = prev[j];
                }
            }
        }
        prev = cur;
    }
    return prev[len];
}
// Time Complexity - O(n*n)
// Space Complexity - O(n)
int solve_dp_SO1(int n, int len)
{
    vector<vector<int>> dp(2, vector<int>(len + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= len; j++)
        {
            if (i < 2)
            {
                dp[i % 2][j] = i;
            }
            else
            {
                if (j >= i)
                {
                    dp[i % 2][j] = max(i * dp[i % 2][j - i], dp[(i - 1) % 2][j]);
                }
                else
                {
                    dp[i % 2][j] = dp[(i - 1) % 2][j];
                }
            }
        }
    }
    return dp[n % 2][len];
}
// Time Complexity - O(n*n
// Space Complexity - O(n*n)
int solve_dp(int n, int len)
{
    vector<vector<int>> dp(n + 1, vector<int>(len + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= len; j++)
        {
            if (i < 2)
            {
                dp[i][j] = i;
            }
            else
            {
                if (j >= i)
                {
                    dp[i][j] = max(i * dp[i][j - i], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    return dp[n][len];
}
// Time Complexity - O(2^n)
// Space Complexity - O(n)
int solve(int n, int len)
{
    if (n < 2)
        return n;

    if (len >= n)
    {
        return max((n)*solve(n, len - n), solve(n - 1, len));
    }
    else
    {
        return solve(n - 1, len);
    }
}

// Problem link - https://leetcode.com/problems/integer-break/description/
int integerBreak(int n)
{
    if (n < 4)
        return n - 1;
    // return solve(n,n);
    // return solve_dp(n,n);
    return solve_dp_SO(n, n);
}