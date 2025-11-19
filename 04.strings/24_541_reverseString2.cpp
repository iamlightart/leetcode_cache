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

// 我的做法，先翻转边界前面的，跳过边界后再通过条的次数来判断是否需要把尾部翻转
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int step_count = 0;
        int i;
        for (i = 0; i < s.size(); i += k)
        {
            // 注意下一次翻转不能越界
            if (step_count % 2 == 0 && i + k < s.size())
            {
                reverseString(s, i, i + k - 1);
            }
            step_count++;
        }
        // 没那么多条件，判断一下跳了奇偶次就可以了。。。
        if (i / k % 2 != 0)
        {
            reverseString(s, i - k, s.size() - 1);
        };
        return s;
    }

    void reverseString(string &s, int start, int end)
    {
        // 注意一半的边界值是<=
        for (int i = start; i <= (start + (end - start) / 2); i++)
        {
            char temp = s[i];
            s[i] = s[end - i + start];
            s[end - i + start] = temp;
        }
    }
};

class Solution2
{
public:
    // 直接判断swap的substr尾部和输入s哪个尾部更小效率更高
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

    void reverseString(string &s, int start, int end)
    {
        // 注意一半的边界值是<=
        for (int i = start; i <= (start + (end - start) / 2); i++)
        {
            // cout << s[i] << " i:" << i << " start:" << start << " end:" << end << s[end - i + start] << endl;
            char temp = s[i];
            s[i] = s[end - i + start];
            s[end - i + start] = temp;
        }
    }
};
