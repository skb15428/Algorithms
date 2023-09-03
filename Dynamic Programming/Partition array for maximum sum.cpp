#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(n*n)
// Space complexity - O(n)
int solve_dp(vector<int> &arr, int n, int x)
{
    vector<int> dp(n + 1);

    for (int i = n; i >= 0; i--)
    {
        if (i == n)
        {
            dp[i] = 0;
        }
        else
        {
            int max_ele = INT_MIN;
            int ans = INT_MIN;
            for (int k = i; k < min(n, i + x); k++)
            {
                max_ele = max(max_ele, arr[k]);
                int par = max_ele * (k - i + 1) + dp[k + 1];
                ans = max(ans, par);
            }
            dp[i] = ans;
        }
    }
    return dp[0];
}
int solve(vector<int> &arr, int i, int n, int x, vector<int> &dp)
{
    if (i >= n)
    {
        return 0;
    }

    if (dp[i] != -1)
    {
        return dp[i];
    }

    int max_ele = INT_MIN;
    int ans = INT_MIN;
    for (int k = i; k < min(n, i + x); k++)
    {
        max_ele = max(max_ele, arr[k]);
        int par = max_ele * (k - i + 1) + solve(arr, k + 1, n, x, dp);
        ans = max(ans, par);
    }
    return dp[i] = ans;
}

// Problem link - https://leetcode.com/problems/partition-array-for-maximum-sum/description/
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();

    // vector<int>dp(n+1,-1);
    // return solve(arr, 0, n, k,dp);

    return solve_dp(arr, n, k);
}