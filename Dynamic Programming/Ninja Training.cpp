#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(N*4*3)
// Space Complexity - O(N*3)
int solve_dp(int n, vector<vector<int>> &pt)
{
    vector<vector<int>> dp(n + 1, vector<int>(4, -1));

    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            int mm = 0;
            for (int k = 0; k < 3; k++)
            {
                if (k != j)
                {
                    mm = max(mm, pt[i - 1][k] + dp[i - 1][k]);
                }
            }
            dp[i][j] = mm;
        }
    }

    return max(dp[n][0], max(dp[n][1], dp[n][2]));
}

// For recurssion
// Time Complexity - O(2^(N*3))
// Space Complexity - O(1)
int solve_rec_mem(int n, vector<vector<int>> &pt, int ind, vector<vector<int>> &dp)
{
    if (n <= 0)
        return 0;
    int mm = INT_MIN;

    if (ind < 3 && dp[n][ind] != -1)
    {
        return dp[n][ind];
    }

    for (int i = 0; i < 3; i++)
    {
        if (i != ind)
        {
            mm = max(mm, pt[n - 1][i] + solve_rec_mem(n - 1, pt, i, dp));
        }
    }
    return dp[n][ind] = mm;
}
int ninjaTraining(int n, vector<vector<int>> &pt)
{
    // vector<vector<int>>dp(n+1,vector<int>(4,-1));
    // return solve(n,pt,3,dp);

    return solve_dp(n, pt);
}