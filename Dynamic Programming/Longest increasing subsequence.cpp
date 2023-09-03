#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(n*log(n))
// Space Complexity - O(n)
int solve_most_optimised(vector<int> &nums, int n) // Using binary search
{
    vector<int> arr;
    arr.push_back(nums[0]);
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > arr.back())
        {
            arr.push_back(nums[i]);
        }
        else
        {
            int ind = lower_bound(arr.begin(), arr.end(), nums[i]) - arr.begin();
            arr[ind] = nums[i];
        }
    }
    return arr.size();
}

// Time Complexity - O(n*n)
// Space Complexity - O(n)
int solve_optimised(vector<int> &nums, int n)
{ // For printing
    vector<int> lis(n, 1);

    vector<int> hash(n);  //
    int lastInd = n - 1;  //
    vector<int> sequence; //

    int maxi = 1;
    for (int i = 1; i < n; i++)
    {
        hash[i] = i; //
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j] && lis[i] < lis[j] + 1)
            {
                hash[i] = j; //
                lis[i] = lis[j] + 1;
            }
        }
        if (maxi < lis[i])
        {
            maxi = lis[i];
            lastInd = i; //
        }
    }

    while (hash[lastInd] != lastInd)
    {                                      //
        sequence.push_back(nums[lastInd]); //
        lastInd = hash[lastInd];           //
    }                                      //
    sequence.push_back(nums[lastInd]);     //

    for (int i = sequence.size() - 1; i >= 0; i--)
    {                               //
        cout << sequence[i] << " "; //
    }                               //
    cout << endl;                   //

    return maxi;
}

// Time Complexity - O(n*n)
// Space Complexity - O(2*n)
int solve_dp_SO(vector<int> &nums, int n)
{
    vector<vector<int>> dp(2, vector<int>(n + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
            {
                dp[i & 1][j] = 0;
            }
            else
            {
                if (j == 0 || nums[i - 1] < nums[j - 1])
                {
                    dp[i & 1][j] = max(1 + dp[(i - 1) & 1][i], dp[(i - 1) & 1][j]);
                }
                else
                {
                    dp[i & 1][j] = dp[(i - 1) & 1][j];
                }
            }
        }
    }
    return *max_element(dp[n & 1].begin(), dp[n & 1].end());
}

// Time Complexity - O(n*n)
// Space Complexity - O(n*n)
int solve_dp(vector<int> &nums, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                if (j == 0 || nums[i - 1] < nums[j - 1])
                {
                    dp[i][j] = max(1 + dp[i - 1][i], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    return *max_element(dp[n].begin(), dp[n].end());
}

// For recursion
// Time Complexity - O(2^n)
// Space Complexity - O(n)
int solve_rec_mem(vector<int> &nums, int n, int ind, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        return 0;
    }

    if (dp[n][ind] != -1)
    {
        return dp[n][ind];
    }

    if (ind == 0 || nums[n - 1] < nums[ind - 1])
    {
        return dp[n][ind] = max(1 + solve_rec_mem(nums, n - 1, n, dp), solve_rec_mem(nums, n - 1, ind, dp));
    }
    else
    {
        return dp[n][ind] = solve_rec_mem(nums, n - 1, ind, dp);
    }
}

// Problem link = https://leetcode.com/problems/longest-increasing-subsequence/description/
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();

    // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    // return solve_rec_mem(nums,n,0,dp);

    // return solve_dp(nums,n);

    // return solve_dp_SO(nums,n);

    // return solve_optimised(nums, n);

    return solve_most_optimised(nums, n);
}