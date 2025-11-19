// https://leetcode.cn/problems/reverse-string-ii/description/
// 2025-11-19
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 直接判断尾部min效率更高
    string reverseStr(string s, int k)
    {
        int should_swap = 1;
        int i;
        for (i = 0; i < s.size(); i += k)
        {

            if (should_swap)
            {
                int end = min(i + k - 1, (int)s.size() - 1);
                reverseString(s, i, end);
                should_swap = 0;
            }
            else
            {
                should_swap = 1;
            }
        }
        return s;
    }

    // 原始做法没写出来，尾部最后很难判断，边界值太多了
    // string reverseStr(string s, int k)
    // {
    //     if (s.size() < k)
    //         return s;
    //     int should_swap = 1;
    //     int i;
    //     for (i = 0; i < s.size(); i += k)
    //     {

    //         if (should_swap && i + k < s.size())
    //         {
    //             reverseString(s, i, i + k - 1);
    //             should_swap = 0;
    //         }
    //         else
    //         {
    //             should_swap = 1;
    //         }
    //     }
    //     这里边界条件特别多，不适合这样做，我也没写全
    //     if (should_swap == 1 && i != s.size() && i - s.size() < k||k==s.size())
    //     {
    //         reverseString(s, i - k, s.size() - 1);
    //     };
    //     return s;
    // }

    void reverseString(string &s, int start, int end)
    {
        // 注意一半的边界值是<=
        for (int i = start; i <= (start + (end - start) / 2); i++)
        {
            cout << s[i] << " i:" << i << " start:" << start << " end:" << end << s[end - i + start] << endl;
            char temp = s[i];
            s[i] = s[end - i + start];
            s[end - i + start] = temp;
        }
    }
};

// int main()
// {
//     Solution s;
//     cout << s.reverseStr("abcd", 4);
// }