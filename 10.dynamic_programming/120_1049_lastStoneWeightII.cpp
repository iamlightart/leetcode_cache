// https://leetcode.cn/problems/last-stone-weight-ii/
#include <iostream>
using namespace std;
class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int total = 0;
        for (int i = 0; i < stones.size(); i++)
        {
            total += stones[i];
        }
        int bag_size = total / 2;

        vector<vector<int>> dp(stones.size() + 1, vector<int>(bag_size + 1, 0));
        for (int i = 1; i <= stones.size(); i++)
        {
            for (int j = 1; j <= bag_size; j++)
            {
                if (j >= stones[i - 1])
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return total - 2 * dp[stones.size()][bag_size];
    }
};