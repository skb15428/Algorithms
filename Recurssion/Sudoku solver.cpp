#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(9^(N*N))
// Space Complexity - O(N*N)
class Solution
{
public:
    bool isSafe(int x, int y, char m, vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][y] == m)
            {
                return false;
            }
            if (board[x][i] == m)
            {
                return false;
            }
            if (board[3 * (x / 3) + (i / 3)][3 * (y / 3) + (i % 3)] == m)
            {
                return false;
            }
        }

        // int k = x/3;
        // int l = y/3;

        // for(int i=0;i<3;i++){
        //     for(int j=0;j<3;j++){
        //         if(board[3*k+i][3*l+j] == m){
        //             return false;
        //         }
        //     }
        // }

        return true;
    }
    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                if (board[i][j] == '.')
                {
                    for (char m = '1'; m <= '9'; m++)
                    {
                        if (isSafe(i, j, m, board))
                        {
                            board[i][j] = m;
                            if (solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};