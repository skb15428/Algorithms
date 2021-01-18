#include <bits/stdc++.h>
using namespace std;

#define ll long long

////////////////////////////////Fermat's Little Theorem - O(log(n))/////////////////////////////////

ll mulmod(ll a, ll b, ll mod)
{
    ll x = 0, y = a % mod;
    while (b > 0)
    {
        if (b & 1)
        {
            x = (x + y) % mod;
        }
        y = (y * 2ll) % mod;
        b /= 2;
    }
    return x % mod;
}
ll binpow(ll a, ll n, ll mod)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = mulmod(res, a, mod); // if two 64bit numbers are multiplyed then overflow can occur
            // res = (res * a) % mod;  if numbers are not large

        n >>= 1;
        a = mulmod(a, a, mod);
        // a = (a * a) % mod; if numbers are not large
    }
    return res % mod;
}
bool isPrime_fermat(ll n, ll itr = 5)
{
    if (n <= 4)
        return n == 2 || n == 3;

    for (ll i = 1; i < itr; i++)
    {
        ll a = 2 + rand() % (n - 3);  // Generate a in range : 2 <= a <= n-2
        ll res = binpow(a, n - 1, n); // a^(n-1) = 1 mod n => Fermat's Theorem

        if (res != 1)
            return false;
    }
    return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////Brute force - O(sqrt(n))//////////////////////////////////////////
// Time Complexity = O(sqrt(n))
bool isPrime(ll n) // <= Optimised method
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

bool isprime(ll n) // Time Complexity O(sqrt(n))
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (ll i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cout << "Enter a number\n";
        cin >> n;
        isPrime(n) ? cout << "prime\n" : cout << "not prime\n";
        isPrime_fermat(n) ? cout << "prime\n" : cout << "not prime\n";
    }
}
