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
            int sum = 0;
            int start = 0;
            for (int i = 0; i < rel_gas.size(); i++)
            {
                sum += rel_gas[i];
                if (sum < 0)
                {
                    sum = 0;
                    start = i + 1;
                }
            }
            return start;
        }
        return -1;
    }
};
class gptSolution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int total = 0;
        int curr = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            int diff = gas[i] - cost[i];
            total += diff;
            curr += diff;

            if (curr < 0)
            {
                start = i + 1;
                curr = 0;
            }
        }

        return total >= 0 ? start : -1;
    }
};
// 循环反复卡住，使用gpt提供的答案了
class WrongLoopSolution
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
            int sum = 0;
            int i = 0;
            int start = 0;
            while (true)
            {
                sum += rel_gas[i];
                i++;
                if (i > rel_gas.size() - 1)
                    i = 0;
                if (sum == 0)
                    return start;
                if (sum < 0)
                {
                    sum = 0;
                    start = i;
                }
                if (sum > 0 && i == start)
                {
                    return start;
                }
            }
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