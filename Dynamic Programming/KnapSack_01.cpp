#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0)
#define ll long long
#define mod 1000000007
#define endl '\n'
#define PI 3.14159265359
#define vi vector<int>
#define vii vector<vector<int>>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vd vector<double>
#define vdd vector<vector<double>>
#define vc vector<char>
#define vcc vector<vector<char>>
#define vb vector<bool>
#define vbb vector<vector<bool>>

#define pre(x, y) fixed << setprecision(y) << x
#define deb(x) cout << #x << " => " << x << endl;

inline ll power(ll base, ll exp, ll md = mod)
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

////////////////////////////////////Recursive - T => O(2^n), S => O(1)//////////////////////////////////
int knapSack_01(vi &val, vi &wt, int W, int n)
{
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] <= W)
        return max(val[n - 1] + knapSack_01(val, wt, W - wt[n - 1], n - 1), knapSack_01(val, wt, W, n - 1));
    else
        return knapSack_01(val, wt, W, n - 1);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////DP - T => O(n*W), S => O(n*W)////////////////////////////////
int knapSack_01_DP(vi &val, vi &wt, int W, int n)
{
    int dp[n + 1][W + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                if (wt[i - 1] <= j)
                    dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}
/////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////DP - T => O(n*W), S => O(W)////////////////////////////////
int knapSack_01_DP_SO(vi &val, vi &wt, int W, int n)
{
    int dp[2][W + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i % 2][j] = 0;
            else
            {
                if (wt[i - 1] <= j)
                    dp[i % 2][j] = max(val[i - 1] + dp[(i - 1) % 2][j - wt[i - 1]], dp[(i - 1) % 2][j]);
                else
                    dp[i % 2][j] = dp[(i - 1) % 2][j];
            }
        }
    }
    return dp[n % 2][W];
}
/////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    FIO;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi val(n);
        vi wt(n);
        for (int i = 0; i < n; i++)
        {
            cin >> val[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> wt[i];
        }
        int W;
        cin >> W;
        cout << knapSack_01(val, wt, W, n) << endl;
        cout << knapSack_01_DP(val, wt, W, n) << endl;
        cout << knapSack_01_DP_SO(val, wt, W, n) << endl;
    }
    return 0;
}
