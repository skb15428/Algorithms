#include <bits/stdc++.h>
using namespace std;

// Time complexity - O(n*sum)
// Space Complexity - O(2*sum)
int solve_dp_SO(vector<int> &arr, int n, int sum)
{
    int dp[2][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
            {
                if (j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
            else if (arr[i - 1] <= j)
            {
                dp[i % 2][j] = dp[(i - 1) % 2][j - arr[i - 1]] + dp[(i - 1) % 2][j];
            }
            else
            {
                dp[i % 2][j] = dp[(i - 1) % 2][j];
            }
        }
    }
    return dp[n % 2][sum];
}
// Time complexity - O(n*sum)
// Space Complexity - O(n*sum)
int solve_dp(vector<int> &arr, int n, int sum)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
            {
                if (j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
            else if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}
// For securssion
// Time complexity - O(2*n)
// Space Complexity - O(n) n is recursion stack space
int solve_rec_mem(vector<int> &nums, int n, int sum, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        if (sum == 0)
            return 1;
        return 0;
    }

    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }
    if (sum >= nums[n - 1])
    {
        return dp[n][sum] = solve_rec_mem(nums, n - 1, sum - nums[n - 1], dp) + solve_rec_mem(nums, n - 1, sum, dp);
    }
    else
    {
        return dp[n][sum] = solve_rec_mem(nums, n - 1, sum, dp);
    }
}

// S1 + S2 = T
// S1 - S2 = D
// 2*S1 = T+D
// S1 = (T+D)/2
int findTargetSumWays(vector<int> &nums, int target)
{
    int T = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        T += nums[i];
    }
    if ((T + target < 0) || ((T + target) % 2 == 1))
    {
        return 0;
    }
    int s1 = (target + T) / 2;

    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(s1 + 1, -1));
    return solve_rec_mem(nums, n, s1, dp);
    return solve_dp(nums, n, s1);
    return solve_dp_SO(nums, n, s1);
}