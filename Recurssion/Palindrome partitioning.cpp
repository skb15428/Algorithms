#include <bits/stdc++.h>
using namespace std;

// Time complexity - O(2^N * N) there are n-1 places where we can partition and we have 2 choices so 2^(N-1) and to find
// out palindrome we multiply it by N
// Space complexity - O(N)
// Problem link - https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
class Solution
{
public:
    bool isPal(string &s, int st, int en)
    {
        while (st <= en)
        {
            if (s[st++] != s[en--])
            {
                return false;
            }
        }
        return true;
    }
    void solve(string &s, vector<vector<string>> &ans, vector<string> &ds, int st)
    {
        if (st == s.size())
        {
            ans.push_back(ds);
            return;
        }

        for (int i = st; i < s.size(); i++)
        {
            if (isPal(s, st, i))
            {
                ds.push_back(s.substr(st, i - st + 1));
                solve(s, ans, ds, i + 1);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> ds;
        solve(s, ans, ds, 0);
        return ans;
    }
};