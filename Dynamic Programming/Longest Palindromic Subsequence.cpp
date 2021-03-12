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

//////////////////////////////Longest Common Subsequence - T=>O(n*m) S=>O(n*m)////////////////////
int longestCommonSubsequence_DP(string s1, int n, string s2, int m)
// int longestCommonSubsequence_DP(string s1, int n, string s2, int m,vii &dp)
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
    cout << "LPS is => " << ans << endl;
    return dp[n][m];
}
//////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////Longest Palindromic subsequence/////////////////////////////////
// Minimum insertion and deletion to convert a string 'a' to string 'b'
int longestPalindromicSubsequence(string s1,int n)
{
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    return longestCommonSubsequence_DP(s1, n, s2, n);
}
//////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    FIO;

    int t = 1;
    cin >> t;
    while (t--)
    {
        string s1;
        cin >> s1;

        cout << longestPalindromicSubsequence(s1, s1.size()) << endl;
    }
    return 0;
}
