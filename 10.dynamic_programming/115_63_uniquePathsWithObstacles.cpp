// https://leetcode.cn/problems/unique-paths-ii/
#include <iostream>
using namespace std;
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 0)
                    obstacleGrid[i][j] = 1;
                else
                    obstacleGrid[i][j] = 0;
            }
        }
        int prev = obstacleGrid[0][0];
        for (int i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0] == 0)
                prev = 0;
            obstacleGrid[i][0] = prev;
        }
        prev = obstacleGrid[0][0];
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[0][j] == 0)
                prev = 0;
            obstacleGrid[0][j] = prev;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 0)
                    continue;
                obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
            }
        }
        return obstacleGrid[m - 1][n - 1];
    }
};