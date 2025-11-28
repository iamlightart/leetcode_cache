// https://leetcode.cn/problems/evaluate-reverse-polish-notation/
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    int calc_res(int a, int b, string op)
    {
        // 注意复制代码时要把条件和return中的 a 操作 b 中的操作一并改掉
        if (op == "+")
            return a + b;
        if (op == "-")
            return a - b;
        if (op == "*")
            return a * b;
        if (op == "/")
            return a / b;
        // 方法一定要有返回值
        return 0;
    };
    bool is_num(string s)
    {
        if (s == "+" || s == "-" || s == "*" || s == "/")
            return false;
        else
            return true;
    }
    int evalRPN(vector<string> &tokens)
    {
        if (!is_num(tokens[0]))
            return 0;
        stack<int> hodor{};
        for (int i = 0; i < tokens.size(); i++)
        {
            if (is_num(tokens[i]))
                // string to integer最简单的方法，c++11 开始支持
                hodor.push(stoi(tokens[i]));
            else
            {
                int num2 = hodor.top();
                hodor.pop();
                int num1 = hodor.top();
                hodor.pop();
                hodor.push(calc_res(num1, num2, tokens[i]));
            }
        }
        return hodor.top();
    }
};