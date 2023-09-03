#include <bits/stdc++.h>
using namespace std;

bool isPal(string &s, int st, int en)
{
    while (st <= en)
    {
        if (s[st++] != s[en--])
        {
            return false;
        }
    }
    return true;
}

// Time Complexity - O(n*n*n)
// Space Complexity - O(n)
int solve_dp(string &s, int n)
{
    vector<int> dp(n + 1);

    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1 || isPal(s, i, n - 1))
        {
            dp[i] = 0;
        }
        else
        {
            int ans = 1e9;
            for (int k = i; k < n; k++)
            {
                if (isPal(s, i, k))
                {
                    int par = 1 + dp[k + 1];
                    ans = min(ans, par);
                }
            }
            dp[i] = ans;
        }
    }
    return dp[0];
}
int solve(string &s, int i, int j, vector<int> &dp)
{

    if (i >= j or isPal(s, i, j))
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int ans = INT_MAX;

    for (int k = i; k < j; k++)
    {
        if (isPal(s, i, k))
        {
            int temp = solve(s, k + 1, j, dp) + 1;
            ans = min(ans, temp);
        }
    }

    return dp[i] = ans;
}

// Problem link - https://leetcode.com/problems/palindrome-partitioning-ii/description/
int minCut(string s)
{
    int n = s.size();

    // vector<int> dp (n+1, -1);
    // return solve (s, 0, n-1, dp);

    return solve_dp(s, n);
}