#include <bits/stdc++.h>
using namespace std;

#define max 100001            // max=sqrt(10^9) if 10^9 is max constraint  
#define ll long long
#define mod 1000000007

vector<bool>isprime(max, true);
vector<ll>prime;

void sieve()
{
    isprime[0] = isprime[1] = false;
    for (int i = 2; i * i < max; i++)
    {
        if (isprime[i])
        {
            for (int j = i * i; j < max; j += i)
            {
                isprime[j] = false;
            }
        }
    }
    for (int i = 2; i < max; i++)
    {
        if (isprime[i])
        {
            prime.push_back(i);
        }
    }
}
void segm(ll l, ll r)
{
    if(l <= 1)
        l=2;
    vector<bool>sprime(r - l + 1, true);
    for (ll i = 0; prime[i] * (ll)prime[i] <= r; i++)
    {
        ll base=((ll)l/prime[i])*(ll)prime[i];
        if (base < l)
        {
            base += prime[i];
        }
        for (ll j = base; j <= r; j += prime[i])
        {
            sprime[j - l] = false;
        }
        if (base == prime[i])
        {
            sprime[base - l] = true;
        }
    }
    //ll mul = 1;
    for (int i = 0; i < sprime.size(); i++)
    {
        if (sprime[i])
        {
            //mul = ((mul % mod) * ((i + l) % mod)) % mod;
            cout << i + l << " ";
        }
    }
    cout << endl;
    //cout << mul << endl;
}

int main() {
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        segm(l, r);
    }
    return 0;
}
