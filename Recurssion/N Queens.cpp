#include <bits/stdc++.h>
using namespace std;

void print(vector<string> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}

// d1 ->  0 1 2 3
//        1 2 3 4
//        2 3 4 5
//        3 4 5 6

// d2 ->  3 2 1 0
//        4 3 2 1
//        5 4 3 2
//        6 5 4 3
bool isSafe(int i, int j, int n, vector<bool> &row, vector<bool> &d1, vector<bool> &d2)
{
    return (row[i] || d1[i + j] || d2[i + (n - 1 - j)]) ? false : true;
}

void solve(int col, int n, vector<string> &board, vector<vector<string>> &ans, vector<bool> &row, vector<bool> &d1, vector<bool> &d2)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(i, col, n, row, d1, d2))
        {
            board[i][col] = 'Q';
            row[i] = true;
            d1[i + col] = true;
            d2[i + (n - 1 - col)] = true;
            solve(col + 1, n, board, ans, row, d1, d2);
            board[i][col] = '.';
            row[i] = false;
            d1[i + col] = false;
            d2[i + (n - 1 - col)] = false;
        }
    }
}

void nqueens(int n)
{
    string temp;
    for (int i = 0; i < n; i++)
    {
        temp.push_back('.');
    }
    vector<string> board;
    for (int i = 0; i < n; i++)
    {
        board.push_back(temp);
    }

    vector<vector<string>> ans;
    vector<bool> row(n, false);
    vector<bool> d1(2 * n - 1, false);
    vector<bool> d2(2 * n - 1, false);

    solve(0, n, board, ans, row, d1, d2);

    for (int i = 0; i < ans.size(); i++)
    {
        print(ans[i]);
    }
}

// Problem link - https://leetcode.com/problems/n-queens/
// Time Complexity -  O(N!)
// O(N!), where ‘N’ is the number of queens and ‘!’ represents factorial.
// For the first row, we check ‘N’ columns, for the second row, we check the N - 1 column and so on. Hence time complexity will be N * (N-1) * (N-2) …. i.e. N!

// Space Complexity - O(N^2)
// O(N^2), where ‘N’ is the number of queens as we are using a 2-D array having N rows and N columns.
int main()
{

    int n;
    cin >> n;

    nqueens(n);

    return 0;
}