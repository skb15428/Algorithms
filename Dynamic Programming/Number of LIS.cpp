#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(n*n)
// Space Complexity - O(n)
int solve(vector<int> &nums, int n)
{
    vector<int> lis(n, 1), count(n, 1);

    int maxi = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                if (lis[i] < lis[j] + 1)
                {
                    lis[i] = lis[j] + 1;
                    count[i] = count[j];
                }
                else if (lis[i] == lis[j] + 1)
                {
                    count[i] += count[j];
                }
            }
        }
        maxi = max(maxi, lis[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (lis[i] == maxi)
        {
            ans += count[i];
        }
    }

    return ans;
}

// Problem link - https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();
    return solve(nums, n);
}