// https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/
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
    string removeDuplicates(string s)
    {
        if (s.size() <= 1)
            return s;
        deque<char> left{};
        string result{};
        left.push_back(s[0]);
        for (int i = 1; i < s.size(); i++)
        {
            if (left.empty() || s[i] != left.back())
            {

                left.push_back(s[i]);
            }
            else
            {
                left.pop_back();
            }
        }
        while (!left.empty())
        {
            result += left.front();
            left.pop_front();
        }
        return result;
    }
};

// 可以用string直接模拟stack，调用push_back和pop_back省去调用开销
class Solution
{
public:
    string removeDuplicates(string s)
    {
        if (s.size() <= 1)
            return s;
        // 直接用 string 模拟栈，省去 deque 和额外拼接的开销
        string stk;
        stk.reserve(s.size()); // 预分配内存，避免多次扩容（关键优化）
        for (char c : s)
        {
            // 栈非空且当前字符等于栈顶 → 弹出栈顶
            if (!stk.empty() && stk.back() == c)
            {
                stk.pop_back();
            }
            else
            {
                stk.push_back(c); // 否则入栈
            }
        }
        // 栈本身就是结果，无需额外处理
        return stk;
    }
};