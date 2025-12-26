// https://leetcode.cn/problems/sudoku-solver/
#include <iostream>
using namespace std;
class Solution
{
private:
    bool solved = false;

public:
    void solveSudoku(vector<vector<char>> &board);

    {
        solveImpl(board);
    }
    void solveImpl(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                if (board[i][j] == '.')
                {
                    for (int k = 1; k <= 9; k++)
                    {
                        if (!row_contains(i, k) && !col_contains(j, k) && !square_contains(i, j, k))
                        {
                            board[i][j] = k + '0';
                            if (i == board.size() - 1 && j == board.size() - 1)
                                return;
                            else
                            {
                                solveImpl(board);
                                board[i][j] = '.';
                            }
                        }
                    }
                }
            }
        }
    }
};