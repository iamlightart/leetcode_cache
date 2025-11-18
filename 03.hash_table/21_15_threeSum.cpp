// https://leetcode.cn/problems/3sum/description/
// 2025-11-17
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

// 这种做法复杂度o(n²)
//  排序复杂度至少是nlog(n),在o(n)和o(n²)之间，
// 如果用双指针法做二数之和，则因为先排序导致复杂度为nlog(n)这大于最优解哈希表o(n),
// 而三数之和因为本身复杂度o(n²),所以可以兼容nlog(n)的复杂度来使用双指针排序，
// 若这时双指针还使用哈希表，由于需要多组解和去重，会因为传解导致复杂度为o(n²logn),比双指针法三数之和更复杂
// 重点是去重 i,left,right值都不能和自己重复
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result{};
        sort(nums.begin(), nums.end());
        if (nums.size() >= 3)
        {
            for (int i = 0; i < nums.size() - 2; i++)
            {
                // 这里的跳法是个数学问题file://./imgs/21_15.png
                //  当 i = 0 → nums[i] = -1 ，让 left 和 right 寻找[-1, x, y] 的组合。
                //  当 i = 1 → nums[i] 还是 - 1， 再次让 left 和 right 寻找[-1, x, y] 的组合。
                //  而i在最左边时，x和y可以尝试的区间是最大的，后面i向右移动不论多少，只要i值不变，
                //  得到的必然是i在最左边时的子集，
                //  所以尝试了第一次后就跳过所有相等的i
                if (i > 0 && nums[i] == nums[i - 1])
                {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;

                while (right > left)
                {
                    int temp_result = nums[i] + nums[left] + nums[right];
                    if (temp_result == 0)
                    {
                        result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                        // break;⚠️不能用break否则会错过其他left+right=nums[i]的其他不同left，right的解
                        // 获得了正确的解之后left,right各先挪动一步，然后根据挪动后的值是否为老值来去重，目的是跳过老值
                        // 因为temp_result得到了解，只动left或者right都会导致temp_result一定不再是需要解，所以两个要一起动
                        // 相同的left都用最左边的值，相同的right都用最右边的值
                        left++;
                        right--;
                        while (right > left && nums[left] == nums[left - 1])
                        {
                            left++;
                        }

                        while (right > left && nums[right] == nums[right + 1])
                        {
                            right--;
                        }
                    }

                    if (temp_result > 0)
                        right--;
                    else if (temp_result < 0)
                        left++;
                }
            }
        }
        return result;
    }
};

// 这种方法对了，但开销太高超时 哈希表用来去重导致复杂度成为了o(n²log(n))
class DeprecatedSolution
{
public:
    set<vector<int>> two_sum(vector<int> &nums, int target_index)
    {
        int target = -nums[target_index];
        int end = target_index;
        unordered_map<int, int> seen{};
        set<vector<int>> result;
        for (int i = 0; i < end; i++)
        {
            vector<int> temp;
            temp.push_back(nums[i]);
            auto it = seen.find(target - nums[i]);
            if (it != seen.end())
            {
                temp.push_back(it->first);
                result.insert(temp);
            }
            else
            {
                seen[nums[i]] = i;
            }
        }
        return result;
    };
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        set<vector<int>> results;
        for (int i = 2; i < nums.size(); i++)
        {
            auto temp_results = two_sum(nums, i);
            for (auto int_vector : temp_results)
            {
                int_vector.push_back(nums[i]);
                results.insert(int_vector);
            }
        }
        return vector<vector<int>>(results.begin(), results.end());
    }
};

// 错误解法
class WrongSolution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<int> my_nums{nums};
        sort(my_nums.begin(), my_nums.end());
        multimap<int, int> hodor{};
        for (size_t i = 0; i < my_nums.size(); i++)
        {
            hodor.insert({my_nums[i], i});
        }
        unordered_set<int> temp_2_sum;
        vector<vector<int>> result;
        for (int i = 0; i < my_nums.size(); i++)
        {
            for (int j = i + 1; j < my_nums.size(); j++)
            {
                int temp = my_nums[i] + my_nums[j];
                // 1. 使用 temp_2_sum 对两数之和去重
                //    → 错误：同一个 sum 可能对应多个不同 i,j 对，每个都可能产生不同的三元组
                //       过早去重会漏掉合法解（如 [0,0,0]）
                if (temp_2_sum.find(temp) != temp_2_sum.end())
                    continue;
                else
                {
                    temp_2_sum.insert(temp);
                    // 2. 使用 multimap.find(-temp) 查找第三个数
                    //    → find 只返回第一个匹配的 key
                    //    → 如果第一个 index 不满足 k>j，后续 index 不会被检查
                    //       会漏掉正确解（如 [0,0,0]）
                    auto it = hodor.find(-temp);
                    // 3. 对 index k 的处理不够全面
                    //    → 当前逻辑只允许 it->second > j 的第一个匹配
                    //    → 对重复值没有遍历，导致重复元素的三元组漏解
                    if (it != hodor.end() && it->second > j)
                    {
                        result.push_back(vector<int>{my_nums[i], my_nums[j], it->first});
                    }
                }
            }
        }
        return result;
    }
};