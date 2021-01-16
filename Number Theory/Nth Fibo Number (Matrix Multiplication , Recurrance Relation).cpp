//   Fibonacci using recurrance relation    Note: We can form this formula for any relation such as 2F1+3F2+4F3=F4

//   [ F1  F2] * | P  Q | = [ F2  F3 ]
//               | R  S |

//   F1*P+F2*R=F2     : P=0 R=1
//   F1*Q+F2*S=F3     : Q=1 S=1 because F1+F2=F3

//   Therefore transition matrix is : | 0  1 |
//                                    | 1  1 |

//   We get Formula as:

//   [ F1  F2 ] * | 0  1 |^(n-1) = [Fn Fn+1]
//                | 1  1 |

#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

vector<vector<ll>> tr(2, vector<ll>(2)), I(2, vector<ll>(2));

vector<vector<ll>> mul(vector<vector<ll>> I, vector<vector<ll>> tr)
{
    vector<vector<ll>> res(2, vector<ll>(2,0));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                res[i][j] += I[i][k] * tr[k][j];
                // for calculating ans mod 10^9+7
                // ll x = (I[i][k] * tr[k][j]) % mod;
                // res[i][j] = (res[i][j] + x) % mod;
            }
        }
    }
    return res;
}
void fib(ll n)
{
    if (n < 2)
    {
        cout << n << endl;
        return;
    }
    if (n == 2)
    {
        cout << 1 << endl;
        return;
    }

    tr[0][0] = 0;
    tr[0][1] = tr[1][0] = tr[1][1] = 1;

    I[0][0] = I[1][1] = 1;
    I[0][1] = I[1][0] = 0;

    n--;        //Because we want transition matrix to power of n-1;
    while (n)
    {
        if (n % 2 == 1)
        {
            I = mul(I, tr);
            n--;
        }
        else
        {
            tr = mul(tr, tr);
            n /= 2;
        }
    }
    cout << (1 * I[0][0]) + (1 * I[1][0]) << endl;
    // for modulus ans
    // cout << (1 * I[0][0]) + (1 * I[1][0]) % mod << endl;
}
int main() // F0 = 0, F1 = 1, F2 = 1, F3 = 2, F4 = 3, F5 = 5, F6 = 8, F7 = 13, F8 = 21
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        fib(n);
    }
}
