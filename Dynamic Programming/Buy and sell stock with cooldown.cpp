#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(2*n)
// Space Complexity - O(2*n)
int solve_dp(vector<int> &prices, int n)
{
    vector<vector<int>> dp(n + 2, vector<int>(2));
    for (int i = n; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            if (i == n)
            {
                dp[i][j] = 0;
            }
            else
            {
                if (j == 1)
                {
                    dp[i][j] = max(dp[i + 1][0] - prices[i], dp[i + 1][1]);
                }
                else
                {
                    dp[i][j] = max(dp[i + 2][1] + prices[i], dp[i + 1][0]);
                }
            }
        }
    }
    return dp[0][1];
}

// Time Complexity - O(2^n)
// Space Complexity - O(n)
int solve_rec_mem(vector<int> &prices, int n, bool canBuy, vector<vector<int>> &dp)
{
    if (n >= prices.size())
    {
        return 0;
    }

    if (dp[n][canBuy] != -1)
    {
        return dp[n][canBuy];
    }

    if (canBuy)
    {
        return dp[n][canBuy] = max(solve_rec_mem(prices, n + 1, false, dp) - prices[n], solve_rec_mem(prices, n + 1, true, dp));
    }
    else
    {
        return dp[n][canBuy] = max(solve_rec_mem(prices, n + 2, true, dp) + prices[n], solve_rec_mem(prices, n + 1, false, dp));
    }
}

// Problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    // vector<vector<int>>dp(n+1,vector<int>(2,-1));
    // return solve_rec_mem(prices,0,true,dp);

    return solve_dp(prices, n);
}
