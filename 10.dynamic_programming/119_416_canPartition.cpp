// https://leetcode.cn/problems/partition-equal-subset-sum/
#include <iostream>
// #include <bits/stdc++.h>
using namespace std;
class gptSolution
{
public:
    bool canPartition(vector<int> &nums)
    {
        // 1. 计算总和，判断是否为偶数（奇数直接返回false）
        int total = 0;
        for (int num : nums)
        {
            total += num;
        }
        if (total % 2 != 0)
        {
            return false;
        }
        int half = total / 2;

        // 2. 初始化DP数组：dp[j]表示容量为j的背包能装的最大和
        vector<int> dp(half + 1, 0);

        // 3. 0-1背包核心逻辑：先遍历每个数字，再倒序遍历背包容量
        for (int num : nums)
        { // 外层：遍历每个数字（每个数只能选一次）
            // 内层：倒序遍历容量（避免重复选同一个数）
            for (int j = half; j >= num; j--)
            {
                // 状态转移：选当前数 或 不选当前数，取最大值
                dp[j] = max(dp[j], dp[j - num] + num);
            }
        }

        // 4. 判断是否能凑出总和的一半
        return dp[half] == half;
    }
};
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int total = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            total += nums[i];
        }
        if (total % 2 == 1)
            return false;
        int half = total / 2;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(half + 1, 0));

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 1; j <= half; j++)
            {
                if (j >= nums[i])
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[nums.size() - 1][half] == half;
    }
};