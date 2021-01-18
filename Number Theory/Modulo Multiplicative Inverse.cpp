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

////////////////////////////////////Fermit's Little Theorem - O(log(m))////////////////////////////////

// a^(m-2) = a^(-1) mod m
ll inverse_mod_fer(ll a, ll m)
{
    return power(a, m - 2, m);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////Extended Euclidean Algo - O(log(n))///////////////////////////

ll ext_gcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    };
    ll x1, y1;
    ll d = ext_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////Modular Multiplicative Inverse using extended Euclidean algo/////////////////

ll inverse_mod_ext(ll a, ll m)
{
    ll x, y;
    ll g = ext_gcd(a, m, x, y);
    if (g != 1)
    {
        cout << "No solution!";
        return -1;
    }
    else
    {
        x = (x % m + m) % m;
        return x;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    FIO;
    
    ll t;
    cin>>t;
    while(t--)
    {
        ll a, m;
        cin >> a >> m;
        cout << inverse_mod_fer(a, m) << endl;
        cout << inverse_mod_ext(a, m) << endl;
    }
    return 0;
}
