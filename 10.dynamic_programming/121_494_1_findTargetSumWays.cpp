// https://leetcode.cn/problems/target-sum/
#include <iostream>
using namespace std;
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        int bag_size = (sum - target) / 2;
        int result = 0;

        vector<vector<int>> dp(nums.size(), vector<int>(bag_size + 1, 0));
        for (int j = 0; j < bag_size; j++)
        {
            dp[0][j] = (nums[0] == j + 1) ? 1 : 0;
        }
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < bag_size; j++)
            {
                if (j >= nums[i])
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[nums.size() - 1][bag_size];
    }
};

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }

        // ❌ 缺少可行性判断：
        // (sum - target) < 0 或奇数时必然无解
        /*
        int bag_size = (sum - target) / 2;
        */

        if (abs(target) > sum)
            return 0; // ✅ 必须
        if ((sum - target) % 2 != 0)
            return 0; // ✅ 必须

        int bag_size = (sum - target) / 2;

        vector<vector<int>> dp(nums.size(),
                               vector<int>(bag_size + 1, 0));

        // ❌ 初始化错误：
        // 1. j 表示“和”，不应该用 j + 1
        // 2. 漏掉 dp[0][0]
        // 3. nums[0] == 0 的情况无法正确处理
        /*
        for (int j = 0; j < bag_size; j++)
        {
            dp[0][j] = (nums[0] == j + 1) ? 1 : 0;
        }
        */

        // ✅ 正确初始化 dp[0][*]
        if (nums[0] == 0)
            dp[0][0] = 2; // +0 / -0 两种
        else
            dp[0][0] = 1; // 不选 nums[0]

        // ❌ 原写法在 nums[0] == 0 时会多算一次
        // dp[0][nums[0]] += 1;
        //
        // 原因：
        // nums[0] == 0 时，这一行等价于 dp[0][0] += 1
        // 与上面的 dp[0][0] = 2 发生重复计数
        if (nums[0] != 0 && nums[0] <= bag_size)
            dp[0][nums[0]] += 1; // ✅ 修复：排除 nums[0] == 0

        for (int i = 1; i < nums.size(); i++)
        {
            // ❌ j 的范围错误：必须包含 bag_size
            // for (int j = 0; j < bag_size; j++)

            for (int j = 0; j <= bag_size; j++) // ✅ 修复
            {
                if (j >= nums[i])
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[nums.size() - 1][bag_size];
    }
};
