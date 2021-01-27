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

int search(vector<int> arr, int n, int x)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
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
        cin >> x;
        int result = search(arr, n, x);
        (result == -1)
            ? cout << "Element is not present in array"
            : cout << "Element is present at index " << result;
    }
    return 0;
}
