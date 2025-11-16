// https://leetcode.cn/problems/valid-anagram/description/
// 2025年11月16日
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s == t)
            return true;
        if (s.size() != t.size() || s.size() == 0 || t.size() == 0)
            return false;
        //  unordered_map<char, int> holder() 错误！ 定义map不要加括号，不然就成了函数定义,
        // 编译器的优先级规则是：任何能被解析为「函数声明」的语句，都会优先按函数声明处理。
        // 用{}可以彻底避免这种问题，unordered_map<char, int> holder{};
        unordered_map<char, int> holder{};
        for (size_t i = 0; i < s.size(); i++)
        {
            holder[s[i]] += 1;
        }
        for (size_t i = 0; i < t.size(); i++)
        {
            holder[t[i]] -= 1;
            if (holder[t[i]] < 0)
                return false;
        }
        return true;
    }
};

// 题干理解错了，不是错位匹配而是乱序字母是否相等
class DeprecatedSolution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s == t)
            return true;
        else
        {
            if (s.size() == 0 || t.size() == 0 || t.size() > s.size())
                return false;
            for (size_t i = 0; i < s.size() - t.size() + 1; i++)
            {
                if (s[i] == t[0])
                {
                    string temp = s.substr(i, t.size());
                    cout << temp << endl;
                    if (temp == t)
                        return true;
                }
            }
        }
        return false;
    }
};
