// https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/
#include <iostream>
using namespace std;
// TODO 标准解还没有看，头不舒服先睡觉了
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.empty())
            return 0;

        // 按气球右边界升序排序
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });

        int arrows = 1;              // 至少需要一支箭
        int curr_end = points[0][1]; // 当前箭射到的最远右边界

        for (int i = 1; i < points.size(); i++)
        {
            // 如果当前气球左边界大于当前箭的右边界，需要新箭
            if (points[i][0] > curr_end)
            {
                arrows++;
                curr_end = points[i][1]; // 更新箭的新右边界
            }
            // 否则当前气球被当前箭射中，不用新箭
        }

        return arrows;
    }
};
// 自己的解，效率偏低
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b)
             {
        if (a[0] != b[0]) {
            return a[0] < b[0]; // 第一位升序
        } else {
            return a[1] < b[1]; // 第二位升序
        } });
        int result = 1;
        int curr_right = points[0][1];
        for (auto unit : points)
        {

            if (unit[1] < curr_right)
            {
                curr_right = unit[1];
            }
            if (unit[0] > curr_right)
            {
                curr_right = unit[1];
                result++;
            }
        }
        return result;
    }
};