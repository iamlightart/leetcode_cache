// https://leetcode.cn/problems/two-sum/description/
// 2025年11月16日
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
// 用 unordered_map 效率更高,时间复杂度为o(n)
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> seen{};
        vector<int> result{};
        for (size_t i = 0; i < nums.size(); i++)
        {
            result.clear();
            result.push_back(i);
            if (seen.find(target - nums[i]) != seen.end())
            {
                result.push_back(seen.find(target - nums[i])->second);
                return result;
            }
            else
            {
                seen[nums[i]] = i;
            }
        }
        return result;
    }
};

// 用multimap复杂度是nlog(n),可以用unordered_map,只需要注意每一次先比较见过的值再将值插入数组，即可避免重复取到当前值
class DeprecatedSolution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        multimap<int, int> hodor{};
        vector<int> result{};
        // hodor.reserve(nums.size());
        for (size_t i = 0; i < nums.size(); i++)
        {
            hodor.insert({nums[i], i});
        }
        for (size_t i = 0; i < nums.size(); i++)
        {
            result.clear();
            result.push_back(i);
            auto range = hodor.equal_range(target - nums[i]);
            for (auto it = range.first; it != range.second; it++)
            {
                if (it->second != i)
                {
                    result.push_back(it->second);
                    return result;
                }
            };
        }
        return result;
    }
};