#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Time Complexity - O(2^N)
// Space Complexity - O(1)
int frogJump_rec(int n, vector<int> &ht)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return abs(ht[0] - ht[1]);
    }
    int l = frogJump_rec(n - 1, ht) + abs(ht[n] - ht[n - 1]);
    int r = frogJump_rec(n - 2, ht) + abs(ht[n] - ht[n - 2]);
    return min(l, r);
}

// Time Complexity - O(N)
// Space Complexity - O(N)
int frogJump_rec_mem(int n, vector<int> &ht, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return abs(ht[0] - ht[1]);
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int l = frogJump_rec_mem(n - 1, ht, dp) + abs(ht[n] - ht[n - 1]);
    int r = frogJump_rec_mem(n - 2, ht, dp) + abs(ht[n] - ht[n - 2]);
    return dp[n] = min(l, r);
}

// Time Complexity - O(N)
// Space Complexity - O(N)
int frogJump_dp(int n, vector<int> &ht)
{
    vector<int> dp(n, 0);

    dp[0] = 0;
    dp[1] = abs(ht[0] - ht[1]);

    for (int i = 2; i < n; i++)
    {

        int l = dp[i - 1] + abs(ht[i] - ht[i - 1]);
        int r = dp[i - 2] + abs(ht[i] - ht[i - 2]);

        dp[i] = min(l, r);
    }

    return dp[n - 1];
}

// Time Complexity - O(N)
// Space Complexity - O(1)
int frogJump_dp_SO(int n, vector<int> &ht)
{
    vector<int> dp(2, 0);

    dp[0] = 0;
    dp[1] = abs(ht[0] - ht[1]);

    for (int i = 2; i < n; i++)
    {

        int l = dp[(i - 1) % 2] + abs(ht[i] - ht[i - 1]);
        int r = dp[(i - 2) % 2] + abs(ht[i] - ht[i - 2]);

        dp[i % 2] = min(l, r);
    }

    return dp[(n - 1) % 2];
}

// Problem link - https://www.codingninjas.com/studio/problems/frog-jump_3621012?leftPanelTab=1
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> ht(n);
        for (int i = 0; i < n; i++)
        {
            cin >> ht[i];
        }

        cout << frogJump_rec(n - 1, ht) << endl;

        vector<int> dp(n, -1);
        cout << frogJump_rec_mem(n - 1, ht, dp) << endl;

        cout << frogJump_dp(n, ht) << endl;

        cout << frogJump_dp_SO(n, ht) << endl;
    }
    return 0;
}