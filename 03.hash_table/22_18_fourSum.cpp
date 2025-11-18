// https://leetcode.cn/problems/4sum/description/
// 2025-11-18
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
// 做法思路是对的，但可以靠提前剪枝达到更好的效果
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result{};
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > target || nums[nums.size() - 1] < target)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int left = j + 1;
                int right = nums.size() - 1;
                while (right > left)
                {
                    // 转型是很耗时的，只需要将第一个转为long，后面的int相加会自动向上转型
                    long temp_result = (long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (temp_result == target)
                    {
                        result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while (right > left && nums[left] == nums[left - 1])
                            left++;
                        while (right > left && nums[right] == nums[right + 1])
                            right--;
                    }
                    else if (temp_result > target)
                        right--;
                    else if (temp_result < target)
                        left++;
                }
            }
        }
        return result;
    }
};