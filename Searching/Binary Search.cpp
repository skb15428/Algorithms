#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0)
#define ll long long
#define mod 1000000007
#define endl '\n'
#define PI 3.14159265359

#define pre(x, y) fixed << setprecision(y) << x
#define deb(x) cout << #x << " => " << x << endl;

ll power(ll base, ll exp, ll md = mod)
{
    base %= md;
    ll res = 1;
    while (exp != 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % md;
        exp >>= 1;
        base = (base * base) % md;
    }
    return res;
}

int rec_binary_search(vector<int> arr, int s, int e, int x) // Time complexity - O(log(n))
{
    if (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            return rec_binary_search(arr, mid + 1, e, x);
        else
            return rec_binary_search(arr, s, mid - 1, x);
    }
    return -1;
}
int binary_search(vector<int> arr, int n, int x)   // Time complexity - O(log(n))
{
    int s = 0, e = n - 1, mid;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return -1;
}
int main()
{
    FIO;

    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int x;
        cin >> x;   // For binary search array should be sorted.
        // int result = binary_search(arr, n, x);
        int result = rec_binary_search(arr, 0, n - 1, x);
        (result == -1)
            ? cout << "Element is not present in array"
            : cout << "Element is present at index " << result;
    }
    return 0;
}
