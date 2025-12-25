// https://leetcode.cn/problems/n-queens/
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        occupied = vector<vector<bool>>(n, vector<bool>(n, false));
        queenImpl(n);
        return results;
    }

private:
    vector<vector<bool>> occupied{};
    vector<string> result;
    vector<vector<string>> results;
    void queenImpl(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!occupied[i][j])
                {
                    modifyBoard(i, j, n, true);
                    string temp = string(n, '.');
                    temp[j] = 'Q';
                    result.push_back(temp);
                    if (result.size() == n)
                        results.push_back(result);
                    queenImpl(n);
                    result.pop_back();
                }
            };
        }
    }
    void modifyBoard(int row, int col, int size, bool stat)
    {
        occupied[row][col] = stat;
        for (int i = 0; i < size; i++)
        {
            occupied[i][col] = stat;
            occupied[row][i] = stat;
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i + j == row + col || i - j == row - col)
                {
                    occupied[i][j] = stat;
                }
            }
        }
    }
};