#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(N*N*N)
// Space Complexity - O(N*N)
int solve_dp(int arr[], int N)
{
    vector<vector<int>> dp(N + 1, vector<int>(N + 1));

    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (i == j)
            {
                dp[i][j] = 0;
            }
            else
            {
                int ans = 1e9;
                for (int k = i; k < j; k++)
                {
                    int steps = (arr[i - 1] * arr[k] * arr[j]) + dp[i][k] + dp[k + 1][j];
                    ans = min(ans, steps);
                }
                dp[i][j] = ans;
            }
        }
    }
    return dp[1][N - 1];
}
int solve(int arr[], int i, int j, vector<vector<int>> &dp)
{
    if (i == j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = 1e9;
    for (int k = i; k < j; k++)
    {
        int steps = (arr[i - 1] * arr[k] * arr[j]) + solve(arr, i, k, dp) + solve(arr, k + 1, j, dp);
        ans = min(ans, steps);
    }
    return dp[i][j] = ans;
}

// Problem link - https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
int matrixMultiplication(int N, int arr[])
{
    // vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
    // return solve(arr,1,N-1,dp);

    return solve_dp(arr, N);
}