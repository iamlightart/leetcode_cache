// https://leetcode.cn/problems/non-overlapping-intervals/description/
#include <iostream>
using namespace std;
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        // ⚠️主要就是这个数学性质，按右端点排序、贪心选择，能选到最多的不重叠区间
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });
        int result = 0;
        int curr_right = INT_MIN;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i][0] < curr_right)
                result++;
            else
                curr_right = intervals[i][1];
        }
        return result;
    }
};