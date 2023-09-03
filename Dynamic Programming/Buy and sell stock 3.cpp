#include <bits/stdc++.h>
using namespace std;

// Time complexity - O(n*2*cap)
// Space Complexity - O(2*2*cap)
int solve_dp_SO(vector<int> &prices, int n, bool canBuy, int cap)
{
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int>(cap + 1)));

    for (int i = n; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k <= cap; k++)
            {
                if (i == n)
                {
                    dp[i & 1][j][k] = 0;
                }
                else if (k == 0 && j == 1)
                {
                    dp[i & 1][j][k] = 0;
                }
                else
                {
                    if (j == 1)
                    {
                        dp[i & 1][j][k] = max(dp[(i + 1) & 1][0][k - 1] - prices[i], dp[(i + 1) & 1][1][k]);
                    }
                    else
                    {
                        dp[i & 1][j][k] = max(dp[(i + 1) & 1][1][k] + prices[i], dp[(i + 1) & 1][0][k]);
                    }
                }
            }
        }
    }
    return dp[0][1][cap];
}

// Time complexity - O(n*2*cap)
// Space Complexity - O(n*2*cap)
int solve_dp(vector<int> &prices, int n, bool canBuy, int cap)
{
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(cap + 1)));

    for (int i = n; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k <= cap; k++)
            {
                if (i == n)
                {
                    dp[i][j][k] = 0;
                }
                else if (k == 0 && j == 1)
                {
                    dp[i][j][k] = 0;
                }
                else
                {
                    if (j == 1)
                    {
                        dp[i][j][k] = max(dp[i + 1][0][k - 1] - prices[i], dp[i + 1][1][k]);
                    }
                    else
                    {
                        dp[i][j][k] = max(dp[i + 1][1][k] + prices[i], dp[i + 1][0][k]);
                    }
                }
            }
        }
    }
    return dp[0][1][cap];
}

// For recursion
// Time complexity - O(2^n)
// Space Complexity - O(n)
int solve(vector<int> &prices, int n, bool canBuy, int cap, vector<vector<vector<int>>> &dp)
{
    if (n == prices.size())
    {
        return 0;
    }
    if (cap == 0 && canBuy == true)
    {
        return 0;
    }

    if (dp[n][canBuy][cap] != -1)
    {
        return dp[n][canBuy][cap];
    }

    if (canBuy)
    {
        return dp[n][canBuy][cap] = max(solve(prices, n + 1, false, cap - 1, dp) - prices[n], solve(prices, n + 1, true, cap, dp));
    }
    else
    {
        return dp[n][canBuy][cap] = max(solve(prices, n + 1, true, cap, dp) + prices[n], solve(prices, n + 1, false, cap, dp));
    }
}

// Problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(2+1,-1)));
    // return solve(prices,0,true,2,dp);

    // return solve_dp(prices,n,true,2);

    return solve_dp_SO(prices, n, true, 2);
}