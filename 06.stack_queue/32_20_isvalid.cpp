// https://leetcode.cn/problems/valid-parentheses/
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
// s[i] == '()' || s[i] == '[]' || s[i] == '{}'
class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() % 2 != 0)
            return false;
        stack<char> left_holder{};
        if (s[0] == ')' || s[0] == ']' || s[0] == '}')
            return false;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                left_holder.push(s[i]);
            else
            {
                // 注意可能出现{}()}{ 这样的情况，需要先去0
                if (left_holder.size() == 0)
                    return false;
                char left_colon = left_holder.top();
                if (s[i] == ')' && left_colon == '(' ||
                    s[i] == ']' && left_colon == '[' ||
                    s[i] == '}' && left_colon == '{')
                {
                    left_holder.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        // （（ 这样的情况需要被去除
        return left_holder.size() == 0 ? true : false;
    }
};