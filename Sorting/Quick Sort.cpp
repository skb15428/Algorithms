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

// Sorting In Place : Yes
// Stable : No
int partition(vector<int>&arr,int l,int r)
{
    int pivot = arr[r];
    int k = l;
    for (int i = l; i < r; i++)
    {
        if(arr[i]<pivot)
        {
            swap(arr[i], arr[k]);
            k++;
        }
    }
    swap(arr[k], arr[r]);
    return k;
}
int rand_partition(vector<int> &arr, int l, int r)
{
    int r_no = (rand() % (r - l + 1)) + l;
    swap(arr[r], arr[r_no]);
    return partition(arr, l, r);
}

// Time Complexity - O(nlog(n))
// Space Complexity - O(1)
void quickSort(vector<int> &arr, int l, int r) 
{
    if (l < r)
    {
        int pi = rand_partition(arr, l, r);
        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);
    }
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
        quickSort(arr, 0, n - 1);
        for (auto x : arr)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
