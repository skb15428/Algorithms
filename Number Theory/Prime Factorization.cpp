#include <bits/stdc++.h>
#define ll long long
#define max 100001
using namespace std;

vector<int> fact(max);

//////////////////////////////Prime Factorization using Sieve - O(log(n))/////////////////////////////
void sieve()
{
    iota(fact.begin(), fact.end(), 0);
    // for (int i = 0; i < max; i++)
    // {
    //     fact[i] = i;
    // }
    for (int i = 2; i * i < max; i++)
    {
        if (fact[i] == i)
        {
            for (int j = i * i; j < max; j += i)
            {
                if (fact[j] == j)
                    fact[j] = i;
            }
        }
    }
}
//Method 1
void factorized(ll n)
{
    int count = 0;
    ll pre = fact[n];
    while (n != 1)
    {
        if(pre==fact[n])
        {
            count++;
        }
        else
        {
            cout << pre << "^" << count << " ";
            pre = fact[n];
            count = 1;
        }
        n /= fact[n];
    }
    cout << pre << "^" << count << " ";
    cout << "\n";
}
//Method 2
void prime_fact(ll n)
{
    while (n != 1)
    {
        cout << fact[n] << " ";
        n /= fact[n];
    }
    cout << endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////Prime Factorization - Brute force - O(sqrt(n))/////////////////////////
void prime_factorization(ll n) 
{
    for (int i = 2; i * i <= n;i++)
    {
        if (n % i == 0)
        {
            int count = 0;
            while (n % i == 0)
            {
                count++;
                n /= i;
            }
            cout << i << "^" << count << " ";
        }
    }
    if (n > 1)
    {
        cout << n << "^" << 1;
    }
    cout << endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve();     // Don't include it for brute force method
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        prime_fact(n);
    }
}
