// https://leetcode.cn/problems/climbing-stairs/
#include <iostream>
using namespace std;
class Solution
{
public:
    // 爬到第 n 阶的所有方法，本质是 “先爬到 n-1 阶，再爬 1 阶” + “先爬到 n-2 阶，再爬 2 阶”
    vector<int> hodor{};
    int climbStairs(int n)
    {
        hodor.resize(n + 1, -1);
        return climbImpl(n);
    }
    int climbImpl(int n)
    {
        if (n <= 2)
            return n;
        if (hodor[n] != -1)
            return hodor[n];
        else
        {
            int result = climbImpl(n - 1) + climbImpl(n - 2);
            hodor[n] = result;
            return result;
        };
    }
};