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

vector<ll> fact(100001);

void mod_fact(ll p)
{
    fact[0] = fact[1] = 1;
    for (int i = 2; i < p; i++)
    {
        fact[i] = (fact[i - 1] * i) % p;
    }
}
///////////////////////////////Using DP - where (p>n) /////////////////////////////////
// Time Complexity - O(n*r) & Space Complexity - O(r)
int nCr_mod_DP(int n, int r, int p)
{
    if (r > n - r)
        r = n - r;
    int C[r + 1];
    memset(C, 0, sizeof(C));

    C[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j - 1]) % p; // nCj = (n-1)Cj + (n-1)C(j-1);
    }
    return C[r];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////Using inverse modulo - where (p>n) /////////////////////////////////
// Time Complexity - O(n * log(p)) & Space Complexity - O(n)
ll nCr_mod(ll n, ll r, ll p)
{
    if (r > n)
        return 0;
    ll res = fact[n];
    res = (res * power(fact[r], p - 2, p)) % p;
    res = (res * power(fact[n - r], p - 2, p)) % p;
    return res;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////Lucas Theorem - where (p<n)//////////////////////////////////
// Time Complexity - O(p2 *Logp n) & Space Complexity - O(p)
ll lucas(ll n, ll r, ll p)
{
    ll ni = n % p, ri = r % p;
    if (ni == ri)
        return 1ll;
    if (ri > ni)
        return 0ll;
    return (lucas(n / p, r / p, p) * nCr_mod_DP(ni, ri, p)) % p;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    FIO;

    ll t;
    ll n, r, p;
    cin >> t;
    while (t--)
    {
        cin >> n >> r >> p;
        mod_fact(p);
        cout << lucas(n, r, p) << endl;
        cout << nCr_mod(n, r, p) << endl;
        cout << nCr_mod_DP(n, r, p) << endl;
    }
    return 0;
}
