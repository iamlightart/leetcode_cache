// https://leetcode.cn/problems/unique-paths/
#include <iostream>
using namespace std;
// 嘿嘿，自己一次ac 100%！
class Solution
{
public:
    vector<vector<int>> hodor{};
    int uniquePaths(int m, int n)
    {
        hodor.resize(m);
        for (int i = 0; i < m; i++)
        {
            hodor[i].resize(n, 1);
        }
        // 注意，[0][0]最好初始化为1，这样只有m==1&&n==1的时候可以直接返回正确的结果
        // ❌hodor[0][0]==0; //虽然初始为[0][0]，但也应该为1，即只有一种方式到达起点1
        for (int i = 1; i < hodor.size(); i++)
        {
            for (int j = 1; j < hodor[i].size(); j++)
            {
                hodor[i][j] = hodor[i - 1][j] + hodor[i][j - 1];
            };
        };
        return hodor[m - 1][n - 1];
    }
};