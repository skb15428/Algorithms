#include <bits/stdc++.h>
using namespace std;

// Time complexity - O(n^m) as for each nodes we have m color possible.
// Space complexity - O(N) There can be N nodes at a time in a stack
// Problem link - https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
bool isPossible(bool graph[101][101], int n, int x, int c, int col[])
{
    for (int i = 0; i < n; i++)
    {
        if (i != x && graph[x][i] == 1 && col[i] == c)
        {
            return false;
        }
    }
    return true;
}
bool solve(bool graph[101][101], int m, int n, int x, int col[])
{
    if (x == n)
    {
        return true;
    }

    for (int i = 1; i <= m; i++)
    {
        if (isPossible(graph, n, x, i, col))
        {
            col[x] = i;
            if (solve(graph, m, n, x + 1, col))
            {
                return true;
            }
            col[x] = 0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n)
{
    int col[n] = {0};
    return solve(graph, m, n, 0, col);
}