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

////////////////////////////////////Recurcive///////////////////////////////////////////////////////
bool subsetSum(vi &arr, int n, int sum)
{
    if (sum == 0)
        return true;
    if (n == 0)
        return false;

    if (arr[n - 1] <= sum)
        return (subsetSum(arr, n - 1, sum - arr[n - 1]) || subsetSum(arr, n - 1, sum));
    else
        return subsetSum(arr, n - 1, sum);
}
////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////DP - T=>O(n*sum), S=>O(n*sum)////////////////////////////////////
//bool subsetSum_DP(vi &arr, int n, int sum)
bool subsetSum_DP(vi &arr, int n, int sum, vbb &dp) // For min Subset Difference
{
    //bool dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
                dp[i][j] = true;
            else if (i == 0)
                dp[i][j] = false;
            else if (arr[i - 1] <= j)
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}
//////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////DP - T=>O(n*sum), S=>O(2*sum)////////////////////////////////////
// Space Optimizeed solution
// Problem requires only previous row for calculating current value
bool subsetSum_DP_SO(vi &arr, int n, int sum)
{
    bool dp[2][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
                dp[i % 2][j] = true;
            else if (i == 0)
                dp[i % 2][j] = false;
            else if (arr[i - 1] <= j)
                dp[i % 2][j] = (dp[(i - 1) % 2][j - arr[i - 1]] || dp[(i - 1) % 2][j]);
            else
                dp[i % 2][j] = dp[(i - 1) % 2][j];
        }
    }
    return dp[n % 2][sum];
}
//////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////Equal sum Partiotion///////////////////////////////////////////////
// Find if array can be divided into two subsets having same sum
bool equalSumPartition(vi &arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum & 1)
        return false;
    else
        return subsetSum_DP_SO(arr, n, sum / 2);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////Count Subsets//////////////////////////////////////////////////////
// Find number of subsets having given sum
int countSubset(vi &arr, int n, int sum)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
                dp[i][j] = 1;
            else if (i == 0)
                dp[i][j] = 0;
            else if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}
///////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////Min Subset Difference///////////////////////////////////////////////
// Find the min difference between two subsets
// Let s1 & s2 be sums of two subsetSum
// we want s2-s1=min
// Let T be Total sum of array
// s1+s2=T
// s2=T-s1
// Therefore T-s1-s1=min ===> T-2*s1=min 
int minSubsetDiff(vi &arr,int n)
{
    int sum = 0;
    for (int i = 0; i < n;i++)
    {
        sum += arr[i];
    }
    vbb dp(n + 1, vb((sum / 2) + 1));

    subsetSum_DP(arr, n, sum / 2, dp);

    for (int i = sum / 2; i >= 0;i--)
    {
        if(dp[n][i]==true)
            return (sum - (2 * i));
    }
    return sum;
}
//////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////Count combination of two subsets with given diff////////////////////
// Let s1 be sum of subset1 and s2 be sum of subset2
//     s1+s2=T
//    +s1-s2=diff
//    ------------
//    2*s1=diff+T

//    s1=(diff+T)/2;
int countDiff(vi &arr,int n,int diff)
{
    int T = 0;
    for (int i = 0; i < n;i++)
    {
        T += arr[i];
    }
    int s1 = (diff + T) / 2;
    return countSubset(arr, n, s1);
}
///////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    FIO;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int sum;
        cin >> sum;
        subsetSum(arr, n, sum) == true ? cout << "Subset found\n" : cout << "Subset not Found\n";
        //subsetSum_DP(arr, n, sum) == true ? cout << "Subset found\n" : cout << "Subset not Found\n";
        subsetSum_DP_SO(arr, n, sum) == true ? cout << "Subset found\n" : cout << "Subset not Found\n";

        equalSumPartition(arr, n) == true ? cout << "Array can be partitioned into equal sum\n" : cout << "Cannot be partitioned\n";

        cout << "There are " << countSubset(arr, n, sum) << " subsets of sum " << sum << endl;

        cout << "Min subset Difference is = " << minSubsetDiff(arr, n)<<endl;

        cout << "No of combination of subsets with given diff is = " << countDiff(arr, n, sum) << endl;
    }
    return 0;
}
