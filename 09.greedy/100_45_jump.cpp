// https://leetcode.cn/problems/jump-game-ii/
#include <iostream>
using namespace std;
// gpt写法，直接遍历，只在达到最远时加step
class gptSolution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int steps = 0;
        int currEnd = 0;
        int farthest = 0;

        for (int i = 0; i < n - 1; i++)
        {
            farthest = max(farthest, i + nums[i]);

            if (i == currEnd)
            {
                steps++;
                currEnd = farthest;
            }
        }
        return steps;
    }
};

// 我的写法用while控制边界
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;
        int pos = 0;
        int step_count = 0;
        int prev_far = 0;
        while (pos < nums.size() - 1)
        {
            int start = pos;
            int gap = nums[pos];
            if (start + gap >= nums.size() - 1)
                return step_count + 1;
            for (int i = start; i <= start + gap; i++)
            {

                if (i + nums[i] > prev_far)
                {
                    prev_far = i + nums[i];
                    pos = i;
                }
            }
            step_count++;
        }
        return step_count;
    }
};