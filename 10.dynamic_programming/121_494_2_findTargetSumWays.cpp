// https://leetcode.cn/problems/target-sum/
// 1.23 ⬇️ 1.27➡️ 2.3 ⬆️
#include <iostream>
using namespace std;

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int total = 0;
        for (auto num : nums)
            total += num;
        // 排除两个不可能解
        if (abs(target) > total)
            return 0; // ✅ 必须
        if ((total - target) % 2 != 0)
            return 0; // ✅ 必须

        int bag_size = (total - target) / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(bag_size + 1, 0));

        // 处理0的极限值，如果nums[0]为0 则+0/-0, 不为0则默认有一个解
        dp[0][0] = (nums[0] == 0) ? 2 : 1;
        if (nums[0] != 0 && nums[0] <= bag_size)
            dp[0][nums[0]] += 1; // ✅ 修复：排除 nums[0] == 0

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j <= bag_size; j++)
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

// 排除无用解
// 初始化行num_size，列bag_size的数组，
// nums[0]为0有+0/-0两种填法，否则0也有一种填法，
// dp[0][nums[0] 有一种填法
// dp数组中，每一个cell的值，
// 为不需要当前nums[i]，也可以充满bag_size的解法数量，dp[i-1][j]
//  加上不需要当前nums[i]时，充满bag_size-nums[i] 的解法数量，因为把nums[i]放进去就刚好是bag-size
// 初始化是最恶心的地方
