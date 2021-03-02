#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0), cin.tie(0)
#define ll long long
#define mod 1000000007
#define endl '\n'
#define PI 3.14159265359
#define vi vector<int>
#define vii vector<vector<int>>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vd vector<double>
#define vdd vector<vector<double>>
#define vc vector<char>
#define vcc vector<vector<char>>
#define vb vector<bool>
#define vbb vector<vector<bool>>

#define pre(x, y) fixed << setprecision(y) << x
#define deb(x) cout << #x << " => " << x << endl;

inline ll power(ll base, ll exp, ll md = mod)
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

//////////////////////////////Longest Common Subsequence (Recursive)///////////////
int longestCommonSubsequence(string s1, int n, string s2, int m)
{
    if (n == 0 || m == 0)
        return 0;
    if (s1[n - 1] == s2[m - 1])
    {
        return 1 + longestCommonSubsequence(s1, n - 1, s2, m - 1);
    }
    else
    {
        return max(longestCommonSubsequence(s1, n, s2, m - 1), longestCommonSubsequence(s1, n - 1, s2, m));
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////Longest Common Subsequence - T=>O(n*m) S=>O(n*m)////////////////////
int longestCommonSubsequence_DP(string s1, int n, string s2, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int i = n, j = m;
    string ans = "";
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << "LCS is => " << ans << endl;
    return dp[n][m];
}
//////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////Longest Common Subsequence - T=>O(n*m) S=>O(m)////////////////////
int longestCommonSubsequence_DP_SO(string s1, int n, string s2, int m)
{
    int dp[2][m + 1];
    bool bi;
    for (int i = 0; i <= n; i++)
    {
        bi = i & 1;
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                // dp[i%2][j] = 0;
                dp[bi][j] = 0;
            else
            {
                if (s1[i - 1] == s2[j - 1])
                    // dp[i%2][j] = 1 + dp[(i - 1)%2][j - 1];
                    dp[bi][j] = 1 + dp[1 - bi][j - 1];
                else
                    // dp[i%2][j] = max(dp[(i - 1)%2][j], dp[i%2][j - 1]);
                    dp[bi][j] = max(dp[1 - bi][j], dp[bi][j - 1]);
            }
        }
    }
    return dp[n % 2][m];
}
//////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    FIO;

    int t = 1;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        cout << longestCommonSubsequence(s1, s1.size(), s2, s2.size()) << endl;
        cout << longestCommonSubsequence_DP(s1, s1.size(), s2, s2.size()) << endl;
        cout << longestCommonSubsequence_DP_SO(s1, s1.size(), s2, s2.size()) << endl;
    }
    return 0;
}
