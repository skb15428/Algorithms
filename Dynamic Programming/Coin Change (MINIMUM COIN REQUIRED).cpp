#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(n*amount)
// Space Complexity - O(2*amount)
int solve_dp_SO(vector<int> coins, int amount, int n)
{
    vector<vector<int>> dp(2, vector<int>(amount + 1, -1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (j == 0)
            {
                dp[i % 2][j] = 0;
            }
            else if (i == 0)
            {
                dp[i % 2][j] = 1e9;
            }
            else if (i == 1)
            {
                if (j % coins[i - 1] == 0)
                    dp[i % 2][j] = j / coins[i - 1];
                else
                    dp[i % 2][j] = 1e9;
            }
            else
            {
                if (j >= coins[i - 1])
                {
                    dp[i % 2][j] = min(1 + dp[i % 2][j - coins[i - 1]], dp[(i - 1) % 2][j]);
                }
                else
                {
                    dp[i % 2][j] = dp[(i - 1) % 2][j];
                }
            }
        }
    }
    return dp[n % 2][amount];
}

// Time Complexity - O(n*amount)
// Space Complexity - O(n*amount)
int solve_dp(vector<int> coins, int amount, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 0;
            }
            else if (i == 0)
            {
                dp[i][j] = 1e9;
            }
            else if (i == 1)
            {
                if (j % coins[i - 1] == 0)
                    dp[i][j] = j / coins[i - 1];
                else
                    dp[i][j] = 1e9;
            }
            else
            {
                if (j >= coins[i - 1])
                {
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    return dp[n][amount];
}

// For Recurssion
// Time Complexity - O(2*n)
// Space Complexity - O(1) + O(k) -> stack space where k is no of coins taken
int solve_rec_mem(vector<int> &coins, int amount, int n, vector<vector<int>> &dp)
{
    if (amount == 0)
        return 0;
    if (n == 0)
        return 1e9;
    if (n == 1)
    {
        if (amount % coins[n - 1] == 0)
            return amount / coins[n - 1];
        else
            return 1e9;
    }

    if (dp[n][amount] != -1)
        return dp[n][amount];

    if (amount >= coins[n - 1])
    {
        return dp[n][amount] = min(1 + solve_rec_mem(coins, amount - coins[n - 1], n, dp), solve_rec_mem(coins, amount, n - 1, dp));
    }
    else
    {
        return dp[n][amount] = solve_rec_mem(coins, amount, n - 1, dp);
    }
}

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();

    // vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
    // int ans = solve_rec_mem(coins,amount,n,dp);

    // int ans = solve_dp(coins,amount,n);

    int ans = solve_dp_SO(coins, amount, n);

    return ans >= 1e9 ? -1 : ans;
}
