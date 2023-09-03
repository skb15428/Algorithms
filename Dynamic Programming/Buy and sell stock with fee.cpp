#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(n)
// Space Complexity - O(1)
int solve_dp_SO(vector<int> &prices, int n, int fee)
{
    vector<vector<int>> dp(2, vector<int>(2, 0));
    for (int i = n - 1; i >= 0; i--)
    { // Removed second loop and added index
        dp[i & 1][1] = max(dp[(i + 1) & 1][0] - prices[i], dp[(i + 1) & 1][1]);
        dp[i & 1][0] = max(dp[(i + 1) & 1][1] + prices[i] - fee, dp[(i + 1) & 1][0]);
    }
    return dp[0][1];
}

// Time Complexity - O(2*n)
// Space Complexity - O(2*n)
int solve_dp(vector<int> &prices, int n, int fee)
{
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 1)
            {
                dp[i][j] = max(dp[i + 1][0] - prices[i], dp[i + 1][1]);
            }
            else
            {
                dp[i][j] = max(dp[i + 1][1] + prices[i] - fee, dp[i + 1][0]);
            }
        }
    }
    return dp[0][1];
}

// For recursion
// Time Complexity - O(2^n)
// Space Complexity - O(n)
int solve_rec_mem(vector<int> &prices, int n, bool canBuy, int fee, vector<vector<int>> &dp)
{
    if (n == prices.size())
    {
        return 0;
    }

    if (dp[n][canBuy] != -1)
    {
        return dp[n][canBuy];
    }

    if (canBuy)
    {
        return dp[n][canBuy] = max(solve_rec_mem(prices, n + 1, false, fee, dp) - prices[n], solve_rec_mem(prices, n + 1, true, fee, dp));
    }
    else
    {
        return dp[n][canBuy] = max(solve_rec_mem(prices, n + 1, true, fee, dp) + prices[n] - fee, solve_rec_mem(prices, n + 1, false, fee, dp));
    }
}

// Problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();

    // vector<vector<int>>dp(n+1,vector<int>(2,-1));
    // return solve_rec_mem(prices,0,true,fee,dp);

    // return solve_dp(prices,n,fee);

    return solve_dp_SO(prices, n, fee);
}