// https://leetcode.cn/problems/4sum-ii/description/
// 2025年11月16日
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <unordered_set>
using namespace std;
// 正确的写法，还是注意复制函数调用时改参数的问题
class Solution
{
public:
    unordered_map<int, int> get_sum(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> result;
        // 提前保留空间避免扩容，reserve就算用不完也不会影响遍历
        result.reserve(nums1.size() * nums2.size());
        for (int i : nums1)
        {
            for (int j : nums2)
            {
                result[i + j]++;
            }
        }
        return result;
    }
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        int result = 0;
        unordered_map<int, int> first_2_sum = get_sum(nums1, nums2);
        // 这里第一次提交num1,num2忘记改为num3,num4导致错误
        unordered_map<int, int> last_2_sum = get_sum(nums3, nums4);

        // 🌟
        // for (auto &it1 : first_2_sum) ，必须写&it1，因为要在遍历中对first_2_sum的每个元素引用，而非复制
        // 编译器会展开成类似的语法for(i)
        // for (auto __it = container.begin(); __it != container.end(); ++__it)
        // {
        //     auto &elem = *__it; // ← 这里的 & 是绑定到容器元素
        // }
        // 如果不写&则底层元素会挨个复制
        // for (auto __it = container.begin(); __it != container.end(); ++__it)
        // {
        //     auto elem = *__it; // ← 这里会挨个复制container中的元素
        // }
        for (auto &it1 : first_2_sum)
        {
            // 先存好iterator it2，少用find可以提高性能
            auto it2 = last_2_sum.find(-it1.first);
            if (it2 != last_2_sum.end())
                result += it1.second * it2->second;
        }
        return result;
    }
};
// 下面的写法去掉了很多重复的解，是错误,在get_sum时不同的组合有相同的值，也会被排除掉
class WrongSolution
{
public:
    unordered_set<int> get_sum(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> result;
        for (int i : nums1)
        {
            for (int j : nums2)
            {
                result.insert(i + j);
            }
        }
        return result;
    }
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        int result = 0;
        unordered_set<int> first_2_sum = get_sum(nums1, nums2);
        unordered_set<int> last_2_sum = get_sum(nums3, nums4);
        for (int val : first_2_sum)
        {
            if (last_2_sum.find(-val) != last_2_sum.end())
                result++;
        }
        return result;
    }
};