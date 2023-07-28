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
    // if (ind == arr.size())
    // {
    //     if (target == 0)
    //     {
    //         ans.push_back(ds);
    //     }
    //     return;
    // }

    // if (arr[ind] <= target)
    // {
    //     ds.push_back(arr[ind]);
    //     combinationSum(arr, ans, ds, ind+1, target - arr[ind]);
    //     ds.pop_back();
    // }
    // combinationSum(arr, ans, ds, ind + 1, target);

    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = ind; i < arr.size(); i++)
    {
        if (i != ind && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > target)
            break;

        ds.push_back(arr[i]);
        combinationSum(arr, ans, ds, i + 1, target - arr[i]);
        ds.pop_back();
    }
}

// Problem link - https://leetcode.com/problems/combination-sum-ii/description/
// Time Complexity - O(2^n*k) where n = no of elements and k = no elements pushed in ans array
// Space Complexity - k*x where x is no of combinations
int main()
{

    vector<int> arr = {1, 1, 1, 2, 2};
    vector<vector<int>> ans;
    vector<int> ds;
    int target = 4;

    sort(arr.begin(), arr.end());
    combinationSum(arr, ans, ds, 0, target);

    for (auto a : ans)
    {
        print(a);
    }

    return 0;
}