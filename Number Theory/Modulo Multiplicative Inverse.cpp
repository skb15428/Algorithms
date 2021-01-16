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
ll moduloInverse(ll a, ll m)
{
    return power(a, m - 2, m);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    FIO;
    
    ll t;
    cin>>t;
    while(t--)
    {
        ll a, m;
        cin >> a >> m;
        cout << moduloInverse(a, m) << endl;
    }
    return 0;
}
