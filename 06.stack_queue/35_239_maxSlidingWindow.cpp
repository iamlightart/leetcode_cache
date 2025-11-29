// https://leetcode.cn/problems/sliding-window-maximum/description/
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <unordered_set>
using namespace std;

// 用list存状态依然爆炸
class BrutalSolution2
{

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {

        if (nums.size() < k || k == 1)
            return nums;
        list<int> hodor{};
        vector<int> result{};
        int max = INT_MIN;
        for (int i = 0; i < k; i++)
        {
            max = nums[i] > max ? nums[i] : max;
            hodor.insert(hodor.begin(), nums[i]);
        }
        hodor.sort();
        result.push_back(max);
        for (int i = k; i <= nums.size() - 1; i++)
        {
            // 步骤1：找第一个匹配值的迭代器
            auto it = find(hodor.begin(), hodor.end(), nums[i - k]);
            // 步骤2：仅删除这一个（有重复也只删第一个）
            if (it != hodor.end())
            { // 避免迭代器越界
                hodor.erase(it);
            }
            max = nums[i] > hodor.back() ? nums[i] : hodor.back();

            hodor.insert(hodor.begin(), nums[i]);
            result.push_back(max);
        }
        return result;
    }
};
class BrutalSolution
{
    // 暴力解,巨大值超时
private:
    int calc_max(deque<int> &nums)
    {
        int max = INT_MIN;
        for (int i : nums)
        {
            max = i > max ? i : max;
        }
        return max;
    }

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        if (nums.size() < k || k == 1)
            return nums;
        deque<int> hodor{};
        vector<int> result{};
        int max = INT_MIN;
        for (int i = 0; i < k; i++)
        {
            max = nums[i] > max ? nums[i] : max;
            hodor.push_back(nums[i]);
        }
        result.push_back(max);
        for (int i = k; i <= nums.size() - 1; i++)
        {
            hodor.pop_front();
            hodor.push_back(nums[i]);
            max = calc_max(hodor);
            result.push_back(max);
        }
        return result;
    }
};
// 存全局最大值思路不对[7,2,4] 结果是[7,4]而不是[7,7]
// class WrongSolution
// {
// public:
//     vector<int> maxSlidingWindow(vector<int> &nums, int k)
//     {
//         if (nums.size() < k || k == 1)
//             return nums;
//         deque<int> hodor{};
//         vector<int> result{};
//         int max = INT_MIN;
//         for (int i = 0; i < k; i++)
//         {
//             max = nums[i] > max ? nums[i] : max;
//             hodor.push_back(nums[i]);
//         }
//         result.push_back(max);
//         for (int i = k; i <= nums.size() - 1; i++)
//         {
//             max = nums[i] > max ? nums[i] : max;
//             hodor.pop_front();
//             hodor.push_back(nums[i]);
//             result.push_back(max);
//         }
//         return result;
//     }
// };
