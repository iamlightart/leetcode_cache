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
// 剪枝需要在可以正确运行的情况下，进行1️⃣for_i 2️⃣for_j 两层剪枝，
// 第三层剪枝3️⃣while(left,right)是否开启都可以正常通过所有测试，但是貌似ai都会觉得第三层会导致漏解
// 我感觉好像第二层的剪枝已经对第三层进行了有效清理，
// 其实第三层就是相当于第二层的min_sum和max_sum都在不满足条件的情况下continue,而不是最小值break，最大值continue
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result{};
        if (nums.size() < 4)
            return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++)
        {
            // 1️⃣i层剪枝：
            //  当前i（第一次进来最小），最小和大于target，证明任何i下的任何sum都大于target，直接不用算了，break
            if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            // 当前i（第一次进来最小），最大和小于target，证明这个i的情况下任何sum都小于target，需要增加i继续尝试，continue
            if ((long)nums[i] + nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3] < target)
                continue;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                // 2️⃣j层剪枝：
                // 当前j（第一次进来最小），最小和大于target，证明任何j下的任何sum都大于target，直接不用算了，break
                if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;
                // 当前j（第一次进来最小），最大和小于target，证明这个j的情况下任何sum都小于target，需要增加i继续尝试，continue
                if ((long)nums[i] + nums[j] + nums[nums.size() - 1] + nums[nums.size() - 2] < target)
                    continue;
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int left = j + 1;
                int right = nums.size() - 1;
                while (right > left)
                {
                    // 转型是很耗时的，只需要将第一个转为long，后面的int相加会自动向上转型
                    long temp_result = 0;
                    // // 3️⃣left right 层剪枝
                    // // 在当前j下（第一次进来最小），最小和大于target，证明任何j下的任何sum都大于target，直接不用算了，break
                    // temp_result = (long)nums[i] + nums[j] + nums[left] + nums[left + 1];
                    // if (temp_result > target)
                    //     break;
                    // // 当前j下（第一次进来最小），最大和小于target，证明这个j的情况下任何sum都小于target，需要增加j继续尝试， 打破while使用break
                    // temp_result = (long)nums[i] + nums[j] + nums[right - 1] + nums[right];
                    // if (temp_result < target)
                    //     break;
                    temp_result = (long)nums[i] + nums[j] + nums[left] + nums[right];
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
// 只开启第三层，或者开启第一层和第三层，依然不会漏解，证明和第二层应该是几乎等价的
class only_tird_layer_Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result{};
        if (nums.size() < 4)
            return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++)
        {
            // // 1️⃣i层剪枝：
            // //  当前i（第一次进来最小），最小和大于target，证明任何i下的任何sum都大于target，直接不用算了，break
            // if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
            //     break;
            // // 当前i（第一次进来最小），最大和小于target，证明这个i的情况下任何sum都小于target，需要增加i继续尝试，continue
            // if ((long)nums[i] + nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3] < target)
            //     continue;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                // // 2️⃣j层剪枝：
                // // 当前j（第一次进来最小），最小和大于target，证明任何j下的任何sum都大于target，直接不用算了，break
                // if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                //     break;
                // // 当前j（第一次进来最小），最大和小于target，证明这个j的情况下任何sum都小于target，需要增加i继续尝试，continue
                // if ((long)nums[i] + nums[j] + nums[nums.size() - 1] + nums[nums.size() - 2] < target)
                //     continue;
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int left = j + 1;
                int right = nums.size() - 1;
                while (right > left)
                {
                    // 转型是很耗时的，只需要将第一个转为long，后面的int相加会自动向上转型
                    long temp_result = 0;
                    // 3️⃣left right 层剪枝
                    // 在当前j下（第一次进来最小），最小和大于target，证明任何j下的任何sum都大于target，直接不用算了，break
                    temp_result = (long)nums[i] + nums[j] + nums[left] + nums[left + 1];
                    if (temp_result > target)
                        break;
                    // 当前j下（第一次进来最小），最大和小于target，证明这个j的情况下任何sum都小于target，需要增加j继续尝试， 打破while使用break
                    temp_result = (long)nums[i] + nums[j] + nums[right - 1] + nums[right];
                    if (temp_result < target)
                        break;
                    temp_result = (long)nums[i] + nums[j] + nums[left] + nums[right];
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

// // 做法思路是对的，但可以靠提前剪枝达到更好的效果
// class NoPruningSolution
// {
// public:
//     vector<vector<int>> fourSum(vector<int> &nums, int target)
//     {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> result{};
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (i > 0 && nums[i] == nums[i - 1])
//                 continue;
//             for (int j = i + 1; j < nums.size(); j++)
//             {
//                 if (j > i + 1 && nums[j] == nums[j - 1])
//                     continue;
//                 int left = j + 1;
//                 int right = nums.size() - 1;
//                 while (right > left)
//                 {
//                     // 转型是很耗时的，只需要将第一个转为long，后面的int相加会自动向上转型
//                     long temp_result = (long)nums[i] + nums[j] + nums[left] + nums[right];
//                     if (temp_result == target)
//                     {
//                         result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
//                         left++;
//                         right--;

//                         while (right > left && nums[left] == nums[left - 1])
//                             left++;

//                         while (right > left && nums[right] == nums[right + 1])
//                             right--;
//                     }
//                     else if (temp_result > target)
//                         right--;
//                     else if (temp_result < target)
//                         left++;
//                 }
//             }
//         }
//         return result;
//     }
// };