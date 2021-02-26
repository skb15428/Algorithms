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

////////////////////////////////////////DP - T => O(n*W), S => O(W)////////////////////////////////
int rodCutting_DP_SO(vi &price, vi &len, int n, int rod_len)
{
    int dp[2][rod_len + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < rod_len + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i % 2][j] = 0;
            else
            {
                if (len[i - 1] <= j)
                    dp[i % 2][j] = max(price[i - 1] + dp[i % 2][j - len[i - 1]], dp[(i - 1) % 2][j]);
                else
                    dp[i % 2][j] = dp[(i - 1) % 2][j];
            }
        }
    }
    return dp[n % 2][rod_len];
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
        vi price(n);
        vi len(n);
        for (int i = 0; i < n; i++)
        {
            cin >> price[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> len[i];
        }
        int rod_len;
        cin >> rod_len;
        cout << rodCutting_DP_SO(price, len, n,rod_len) << endl;
    }
    return 0;
}    
