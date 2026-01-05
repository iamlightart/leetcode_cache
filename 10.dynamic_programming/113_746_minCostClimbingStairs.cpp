// https://leetcode.cn/problems/min-cost-climbing-stairs/
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> hodor;
    int minCostClimbingStairs(vector<int> &cost)
    {
        hodor.resize(cost.size(), -1);
        climbImpl(cost);
        return hodor.back();
    }
    void climbImpl(vector<int> &cost)
    {
        for (int i = 0; i < hodor.size(); i++)
        {
            if (i == 0)
                hodor[i] = cost[0];
            if (i == 1)
                hodor[i] = cost[1];
            else
            {
                hodor[i] = cost[i] + min(cost[i - 1], cost[i - 2]);
            }
        }
    }
};