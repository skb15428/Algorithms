#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(M*M*M)
// Space Complexity - O(M*M)
int solve_dp(vector<int> &cuts, int m)
{
    vector<vector<int>> dp(m + 1, vector<int>(m + 1));

    for (int i = m - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < m; j++)
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
                    int cut = (cuts[j] - cuts[i - 1]) + dp[i][k] + dp[k + 1][j];
                    ans = min(ans, cut);
                }
                dp[i][j] = ans;
            }
        }
    }
    return dp[1][m - 1];
}
int solve(vector<int> &cuts, int i, int j, vector<vector<int>> &dp)
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
        int cut = (cuts[j] - cuts[i - 1]) + solve(cuts, i, k, dp) + solve(cuts, k + 1, j, dp);
        ans = min(ans, cut);
    }

    return dp[i][j] = ans;
}

// Problem link - https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/
int minCost(int n, vector<int> &cuts)
{
    sort(cuts.begin(), cuts.end());
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);

    int m = cuts.size();

    // vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
    // return solve(cuts,1,m-1,dp);

    return solve_dp(cuts, m);
}