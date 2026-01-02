// https://leetcode.cn/problems/merge-intervals/
#include <iostream>
using namespace std;
// gpt标准解，ac60%
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return {};

        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 return a[0] < b[0];
             });

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] <= res.back()[1])
            {
                // 有重叠，直接扩展右边界
                // ⚠️ back是用来取最后一个值的语法
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else
            {
                // 无重叠，开启新区间
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

// 自己做出来了
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() <= 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });
        vector<vector<int>> results;
        int left = intervals[0][0];
        int right = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int> curr = intervals[i];
            if (curr[0] <= right)
            {
                right = max(right, curr[1]);
                if (curr[0] < left)
                    left = curr[0];
            }
            else
            {
                results.push_back({left, right});
                left = curr[0];
                right = curr[1];
            }
            if (i == intervals.size() - 1)
                results.push_back({left, right});
        }
        return results;
    }
};