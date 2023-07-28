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

// Method 1
void printAllSequences(vector<int> &arr, vector<int> &ans, int x)
{
    print(ans);
    for (int i = x; i < arr.size(); i++)
    {
        ans.push_back(arr[i]);
        printAllSequences(arr, ans, i + 1);
        ans.pop_back();
    }
}

// Method 2
void printAllSequences2(vector<int> &arr, vector<int> &ans, int x)
{
    if (x >= arr.size())
    {
        print(ans);
        return;
    }

    ans.push_back(arr[x]);
    printAllSequences2(arr, ans, x + 1);
    ans.pop_back();
    printAllSequences2(arr, ans, x + 1);
}

// Time Complexity - O(2^n * n)
// Space Complexity - O(n)
int main()
{
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);

    vector<int> ans;
    printAllSequences(arr, ans, 0);
    // printAllSequences2(arr, ans, 0);
    return 0;
}