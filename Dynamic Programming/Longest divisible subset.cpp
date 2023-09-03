#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(n*n)
// Space Complexity - O(n)
vector<int> solve(vector<int> &nums, int n)
{
    vector<int> lds(n, 1);
    vector<int> hash(n);

    int maxLen = 1;
    int lastInd = 0;
    for (int i = 1; i < n; i++)
    {
        hash[i] = i;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] % nums[j] == 0 && lds[i] < lds[j] + 1)
            {
                lds[i] = lds[j] + 1;
                hash[i] = j;
            }
        }
        if (maxLen < lds[i])
        {
            maxLen = lds[i];
            lastInd = i;
        }
    }

    vector<int> ans;

    while (lastInd != hash[lastInd])
    {
        ans.push_back(nums[lastInd]);
        lastInd = hash[lastInd];
    }

    ans.push_back(nums[lastInd]);

    return ans;
}

// Problem link - https://leetcode.com/problems/largest-divisible-subset/description/
vector<int> largestDivisibleSubset(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    return solve(nums, n);
}