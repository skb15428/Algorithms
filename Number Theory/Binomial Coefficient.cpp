#include<bits/stdc++.h>
using namespace std;

# define ll long long
# define mod 1000000007
# define endl '\n'
# define PI 3.14159265359

#define pre(x,y) fixed<<setprecision(y)<<x
#define deb(x) cout << #x << " => " << x << endl;

ll power(ll base, ll exp, ll md=mod)
{
    base %= md;
    ll res = 1;
    while (exp != 0)
    {
        if (exp % 2 == 1)
            res = (res*base) % md;
        exp >>= 1;
        base = (base*base) % md;
    }
    return res;
}

#define FIO ios_base ::sync_with_stdio(false);\
    cin.tie(NULL);\
    cout.tie(NULL);

vector<ll> fact(100001);

///////////////////////////////Using inverse modulo - where (mod>n) /////////////////////////////////

ll C(ll n, ll k)
{
    if(k>n)
        return 0;
    ll res = fact[n];
    res = (res * power(fact[k], mod - 2, mod)) % mod;
    res = (res * power(fact[n - k], mod - 2, mod)) % mod;
    return res;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    FIO;

    fact[0] = fact[1] = 1;
    for (int i = 2; i < 100001;i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    ll q;
    ll n, k;
    cin >> q;
    while(q--)
    {
        cin >> n >> k;
        cout << C(n, k) << endl;
    }
    return 0;
}
