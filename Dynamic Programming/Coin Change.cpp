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

///////////////////////////////////Coin Change - T=>O(n*sum) S=>O(sum)///////////////////////////////
// Find number of subsets having given sum
int coinChange_SO(vi &coin, int n, int sum)
{
    int dp[2][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
                dp[i % 2][j] = 1;
            else if (i == 0)
                dp[i % 2][j] = 0;
            else if (coin[i - 1] <= j)
            {
                dp[i % 2][j] = dp[i % 2][j - coin[i - 1]] + dp[(i - 1) % 2][j];
            }
            else
            {
                dp[i % 2][j] = dp[(i - 1) % 2][j];
            }
        }
    }
    return dp[n % 2][sum];
}
//////////////////////////////////////////////////////////////////////////////////////////////////

// Given a value N, if we want to make change for N cents, and we have infinite supply of each 
// of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins
// doesn’t matter.
int main()
{
    FIO;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi coin(n);
        for (int i = 0; i < n; i++)
        {
            cin >> coin[i];
        }
        int sum;
        cin >> sum;

        cout << coinChange_SO(coin, n, sum) << endl;
    }
    return 0;
}
