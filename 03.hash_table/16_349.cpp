// https://leetcode.cn/problems/intersection-of-two-arrays/description/
// 2025年11月16日
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// 分配set大小，用短串来做hodor效率更高
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // 这样优化保证nums1永远是短串
        if (nums1.size() > nums2.size())
            return intersection(nums2, nums1);

        unordered_set<int> hodor{};
        unordered_set<int> result{};
        // ‼️关键在于提前reserve set的大小，如没有reserve只打败25%，reserve直接100%
        hodor.reserve(nums1.size());
        result.reserve(nums2.size());

        for (size_t i = 0; i < nums1.size(); i++)
        {
            hodor.insert(nums1[i]);
        }

        for (size_t i = 0; i < nums2.size(); i++)
        {
            if (hodor.find(nums2[i]) != hodor.end())
                result.insert(nums2[i]);
        };
        return vector<int>(result.begin(), result.end());
    }
};
// 效率不是很高的我的解，没有调转输入长度（影响不大），也没有初始化set的大小
class DeprecatedSolution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> hodor{};
        unordered_set<int> result{};
        for (size_t i = 0; i < nums1.size(); i++)
        {
            hodor.insert(nums1[i]);
        }

        for (size_t i = 0; i < nums2.size(); i++)
        {
            if (hodor.find(nums2[i]) != hodor.end())
                result.insert(nums2[i]);
        };
        return vector<int>(result.begin(), result.end());
    }
};