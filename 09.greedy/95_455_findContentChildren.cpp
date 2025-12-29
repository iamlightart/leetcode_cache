// https://leetcode.cn/problems/assign-cookies
#include <iostream>
using namespace std;
// 排序完直接匹配即可，也能ac但效率低
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        int result = 0;

        int pos = 0;
        for (int i = 0; i < s.size(); i++)
        {
            // 在评判是否满足时，g不应该和s一一对应，而是有一个s满足了g，g才再挪动一步
            if (s[i] >= g[pos])
            {
                result++;
                pos++;
                if (pos == g.size())
                    break;
            }
        }
        return result;
    }
};
// 计算出start的方式进行匹配，大概80%
class MySolution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        int result = 0;
        int start = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= g[0])
            {
                start = i;
                break;
            }
        }
        if (start == -1)
            return 0;
        else
        {
            int pos = 0;
            for (int i = start; i < s.size(); i++)
            {
                // 在评判是否满足时，g不应该和s一一对应，而是有一个s满足了g，g才再挪动一步
                if (s[i] >= g[pos])
                {
                    result++;
                    pos++;
                    if (pos == g.size())
                        break;
                }
            }
        }
        return result;
    }
};