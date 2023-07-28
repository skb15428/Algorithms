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

void permution(string &str, vector<string> &ans, string &ds, vector<bool> &fre)
{
    if (ds.size() == str.size())
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < str.size(); i++)
    {
        if (!fre[i])
        {
            fre[i] = true;
            ds.push_back(str[i]);
            permution(str, ans, ds, fre);
            ds.pop_back();
            fre[i] = false;
        }
    }
}

void permution2(string &str, vector<string> &ans, int ind)
{
    if (ind == str.size())
    {
        ans.push_back(str);
        return;
    }

    for (int i = ind; i < str.size(); i++)
    {
        swap(str[i], str[ind]);
        permution2(str, ans, ind + 1);
        swap(str[i], str[ind]);
    }
}

// Problem link -
// Time Complexity - n!*n
// Space Complexity - For 1 -> O(n), For 2 -> O(1)
int main()
{

    string str = "abc";
    vector<string> ans;
    string ds;
    vector<bool> fre(str.size());

    // permution(str, ans, ds, fre);
    permution2(str, ans, 0);

    for (auto s : ans)
    {
        cout << s << endl;
    }
    return 0;
}