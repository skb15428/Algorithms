#include<bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0),cin.tie(0)
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

//////////////////////////////////Chinese Remainder Theorem////////////////////////////////////////
//ans = r1(mod b1);
//ans = r2(mod b2);
//ans = r3(mod b3);

ll inverse_mod(ll a, ll p)
{
    return power(a, p - 2, p);
}
ll fun(vector<ll> b, vector<ll> r)
{
    ll N = 1;
    for (int i = 0; i < b.size(); i++)
    {
        N *= b[i];
    }
    ll ans = 0, num;
    for (int i = 0; i < b.size(); i++)
    {
        num = N / b[i];
        ans += num * inverse_mod(num, b[i]) * r[i];
    }
    ans %= N;
    return ans;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    FIO;

    int t;
    cin >> t;
    while (t--)
    {
        int len;
        cin >> len;
        vector<ll> b(len), r(len);
        for (int i = 0; i < len; i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i < len; i++)
        {
            cin >> r[i];
        }
        cout << fun(b, r) << endl;
    }
    return 0;
}
