#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define max 100001
vector<ll> phi_arr(max);

/////////////////////////////Euler's Totient Function - O(sqrt(n))////////////////////////////////////
// Formula - phi(n) = n * (p1-1)/p1 * (p2-1)/p2 * ... * (pk-1)/pk where p1,p2... are prime factor of n
int phi(int n) // Returns number of coprimes below n
{
    int res = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
            }
            res /= i;
            res *= (i - 1);
        }
    }
    if (n > 1)
    {
        res /= n;
        res *= (n - 1);
    }
    return res;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////Euler's Totient function - O(n*log(log(n)))/////////////////////////
// Used if there are more queries for phi

void phi_sieve()
{
    iota(phi_arr.begin(), phi_arr.end(), 0);

    for (int i = 2; i < max; i++)
    {
        if (phi_arr[i] == i)
        {
            for (int j = i; j < max; j += i)
            {
                phi_arr[j] /= i;
                phi_arr[j] *= (i - 1);
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    phi_sieve();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << phi(n) << endl;
        cout << phi_arr[n] << endl;
    }
    return 0;
}
