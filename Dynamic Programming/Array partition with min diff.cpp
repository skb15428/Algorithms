#include <bits/stdc++.h>
using namespace std;

// Time complexity - O(n*m)
// Space Complexity - O(2*m)
int subsetSum_dp_SO(vector<int> &nums, int n, int sum, int total)
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
    for (int i = sum; i >= 0; i--)
    {
        if (dp[n % 2][i])
        {
            return abs((2 * i) - total);
        }
    }
    return sum;
}

// Time complexity - O(n*m)
// Space Complexity - O(n*m)
int subsetSum_dp(vector<int> &nums, int n, int sum, int total)
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

    for (int i = sum; i >= 0; i--)
    {
        if (dp[n][i])
        {
            return abs((2 * i) - total);
        }
    }
    return sum;
}
int minSubsetSumDifference(vector<int> &arr, int n)
{
    int sum = 0;
    for (auto x : arr)
    {
        sum += x;
    }
    // return subsetSum_dp(arr,n,sum/2,sum);

    return subsetSum_dp_SO(arr, n, sum / 2, sum);
}
