#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(N*N*N)
// Space Complexity - O(N*N)
int solve_dp(vector<int> &nums, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    for (int i = n - 2; i >= 1; i++)
    {
        for (int j = i; j <= n - 2; j++)
        {
            int ans = -1e9;
            for (int k = i; k <= j; k++)
            {
                int burst = (nums[i - 1] * nums[k] * nums[j + 1]) + dp[i][k - 1] + dp[k + 1][j];
                ans = max(ans, burst);
            }
            dp[i][j] = ans;
        }
    }
    return dp[1][n - 2];
}
int solve(vector<int> &nums, int i, int j, vector<vector<int>> &dp)
{
    if (i > j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = -1e9;
    for (int k = i; k <= j; k++)
    {
        int burst = (nums[i - 1] * nums[k] * nums[j + 1]) + solve(nums, i, k - 1, dp) + solve(nums, k + 1, j, dp);
        ans = max(ans, burst);
    }
    return dp[i][j] = ans;
}

// Problem link - https://leetcode.com/problems/burst-balloons/description/
int maxCoins(vector<int> &nums)
{
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(nums, 1, n - 2, dp);
}