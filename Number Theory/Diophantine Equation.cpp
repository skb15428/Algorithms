#include <bits/stdc++.h>
using namespace std;

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

#define FIO                            \
    ios_base ::sync_with_stdio(false); \
    cin.tie(NULL);                     \
    cout.tie(NULL);

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

/////////////////////////////////Diophantine Equation - O(log(n))//////////////////////////////////

bool dia_equ(ll a, ll b, ll c, ll &x, ll &y)
{
    ll x0, y0;
    ll g = ext_gcd(a, b, x0, y0);
    if (c % g != 0)
    {
        return false;
    }

    x = x0 * (c / g);
    y = y0 * (c / g);

    if (a < 0)
        x = -x;
    if (b < 0)
        y = -y;

    return true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    FIO;

    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, c, x, y;
        cin >> a >> b >> c;
        if (dia_equ(a, b, c, x, y) == false)
        {
            cout << "No Solution" << endl;
        }
        else
        {
            cout << "x : " << x << " y : " << y << endl;
        }
    }
    return 0;
}
