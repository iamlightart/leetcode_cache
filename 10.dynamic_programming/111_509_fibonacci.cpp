// https://leetcode.cn/problems/fibonacci-number/
#include <iostream>
using namespace std;
#include <map>
class Solution
{
public:
    vector<int> hodor;
    int fib(int n)
    {
        hodor.resize(n + 1, -1);
        return fibImpl(n);
    }
    int fibImpl(int n)
    {
        if (n <= 1)
            return n;
        if (hodor[n] != -1)
            return hodor[n];
        else
        {
            int result = fibImpl(n - 1) + fibImpl(n - 2);
            hodor[n] = result;
            return result;
        }
    }
};

class MySolution
{
public:
    unordered_map<int, int> hodor{};
    int fib(int n)
    {
        int result = 0;
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        // 用count来确定是否已经有n的值
        if (hodor.count(n))
            return hodor[n];
        else
        {
            int result = fib(n - 1) + fib(n - 2);
            hodor[n] = result;
            return result;
        }
    }
};