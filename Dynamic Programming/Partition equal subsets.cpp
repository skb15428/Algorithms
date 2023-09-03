#include <bits/stdc++.h>
using namespace std;

// Time complexity - O(n*m)
// Space Complexity - O(2*m)
bool subsetSum_dp_SO(vector<int> &nums, int n, int sum)
{
    vector<vector<bool>> dp(2, vector<bool>(sum + 1, -1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
            {
                dp[i % 2][j] = true;
            }
            else if (i == 0)
            {
                dp[i % 2][j] = false;
            }
            else
            {
                if (j >= nums[i - 1])
                {
                    dp[i % 2][j] = dp[(i - 1) % 2][j - nums[i - 1]] || dp[(i - 1) % 2][j];
                }
                else
                {
                    dp[i % 2][j] = dp[(i - 1) % 2][j];
                }
            }
        }
    }
    return dp[n % 2][sum];
}

// Time complexity - O(n*m)
// Space Complexity - O(n*m)
bool subsetSum_dp(vector<int> &nums, int n, int sum)
{
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, -1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
            {
                dp[i][j] = true;
            }
            else if (i == 0)
            {
                dp[i][j] = false;
            }
            else
            {
                if (j >= nums[i - 1])
                {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    return dp[n][sum];
}

// For Recurssion
// Time complexity - O(2^n)
// Space Complexity - O(2*m)
bool subsetSum_rec_mem(vector<int> &nums, int n, int sum, vector<vector<int>> &dp)
{
    if (sum == 0)
        return true;
    if (n <= 0)
    {
        return false;
    }

    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }

    if (sum >= nums[n - 1])
    {
        return dp[n][sum] = subsetSum_rec_mem(nums, n - 1, sum - nums[n - 1], dp) || subsetSum_rec_mem(nums, n - 1, sum, dp);
    }
    else
    {
        return dp[n][sum] = subsetSum_rec_mem(nums, n - 1, sum, dp);
    }
}

bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (auto x : nums)
    {
        sum += x;
    }
    if (sum % 2 != 0)
        return false;
    int n = nums.size();
    int m = sum / 2;

    // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    // return subsetSum_rec_mem(nums,n,m,dp);

    // return subsetSum_dp(nums,n,m);

    return subsetSum_dp_SO(nums, n, m);
}