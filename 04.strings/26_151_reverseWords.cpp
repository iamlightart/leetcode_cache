// https://leetcode.cn/problems/reverse-words-in-a-string/
//  2025-11-20
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
    void reverseString(string &s, int start, int end)
    {
        for (size_t i = start; i <= (start + (end - start) / 2); i++)
        {
            char temp = s[i];
            s[i] = s[end - i + start];
            s[end - i + start] = temp;
        }
    }

    string reverseWords(string s)
    {

        int start = 0, end = s.size() - 1;
        string result = "";
        // 先去掉首尾比较好，不然遍历只能单向另一个方向的临界问题不好处理
        while (s[start] == ' ')
            start++;
        while (s[end] == ' ')
            end--;

        for (int i = end; i >= start; i--)
        {
            if (s[i] == ' ')
                continue;
            else
            {
                result += s[i];
                if (i - 1 >= start && s[i - 1] == ' ')
                    result += ' ';
            }
        }

        // 从这里开始不用s而用result,result已经处理好空格
        start = 0;
        end = 0;
        // 注意start不要越界
        while (start < result.size())
        {
            if (result[start] == ' ')
            {
                // 忘记挪start了！
                start++;
                continue;
            }

            else
            {
                end = start;
                // 注意end不要越界
                while (end < result.size() && result[end] != ' ')
                    end++;
                // 翻转的应该是result
                reverseString(result, start, end - 1);
                start = end + 1;
            }
        }
        return result;
    }
};