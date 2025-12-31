#include <iostream>
using namespace std;
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        vector<int> rel_gas(gas.size());
        int has_result = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            rel_gas[i] = gas[i] - cost[i];
            has_result += rel_gas[i];
        }
        if (has_result < 0)
            return -1;
        else
        {
                }
        return -1;
    }
};

// 思路不成立，[3,4,5,1,2]无法通过，需要评估的是最大积累区间
class WrongSolution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        vector<int> rel_gas(gas.size());
        int has_result = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            rel_gas[i] = gas[i] - cost[i];
            has_result += rel_gas[i];
        }
        if (has_result < 0)
            return -1;
        else
        {
            int curr_sum = rel_gas[0];
            int peak_idx = 0;
            for (int i = 1; i < rel_gas.size(); i++)
            {
                if (curr_sum < 0 && rel_gas[i] > 0)
                {
                    peak_idx = i;
                }
                curr_sum += rel_gas[i];
            }
            return peak_idx;
        }
        return -1;
    }
};