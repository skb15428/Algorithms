#include <bits/stdc++.h>
using namespace std;

// Time complexity - O(2^(N * N))
// Space complexity - O(N*N)
// Problem link - https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char mov[4] = {'U', 'D', 'L', 'R'};

bool isPossible(vector<vector<int>> &maze, int n, int x, int y, vector<vector<bool>> &vis)
{
    if (x >= 0 && x < n && y >= 0 && y < n && vis[x][y] == false && maze[x][y] == 1)
    {
        return true;
    }
    return false;
}
void solve(vector<vector<int>> &maze, int n, vector<string> &ans, string &ds, int x, int y, vector<vector<bool>> &vis)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (isPossible(maze, n, x + dx[i], y + dy[i], vis))
        {
            ds.push_back(mov[i]);
            vis[x + dx[i]][y + dy[i]] = true;
            solve(maze, n, ans, ds, x + dx[i], y + dy[i], vis);
            ds.pop_back();
            vis[x + dx[i]][y + dy[i]] = false;
        }
    }
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    string ds;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    vis[0][0] = true;
    if (m[0][0] == 1)
        solve(m, n, ans, ds, 0, 0, vis);

    return ans;
}