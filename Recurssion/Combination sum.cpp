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

void combinationSum(vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds, int ind, int target)
{
    if (ind == arr.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }

    if (arr[ind] <= target)
    {
        ds.push_back(arr[ind]);
        combinationSum(arr, ans, ds, ind, target - arr[ind]);
        ds.pop_back();
    }
    combinationSum(arr, ans, ds, ind + 1, target);
}

// Problem link - https://leetcode.com/problems/combination-sum/description/
// Time Complexity -
// Space Complexity -
int main()
{

    vector<int> arr = {2, 3, 6, 7};
    vector<vector<int>> ans;
    vector<int> ds;
    int target = 8;
    combinationSum(arr, ans, ds, 0, target);
    for (auto a : ans)
    {
        print(a);
    }
    return 0;
}