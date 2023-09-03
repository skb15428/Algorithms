#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(n*n)
// Space Complexity - O(n)
int LongestBitonicSequence(vector<int> nums)
{
    int n = nums.size();

    vector<int> lis(n, 1);
    vector<int> lds(n, 1);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
            }
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (nums[i] > nums[j] && lds[i] < lds[j] + 1)
            {
                lds[i] = lds[j] + 1;
            }
        }
    }

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, lis[i] + lds[i] - 1);
    }

    return ans;
}