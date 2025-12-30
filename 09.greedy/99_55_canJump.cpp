// https://leetcode.cn/problems/jump-game/
#include <iostream>
using namespace std;
// gpt的贪心策略，会动态调整 condition
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int far = 0;
        // ⚠️很巧妙的动态调整 condition
        for (int i = 0; i <= far; i++)
        {
            // 保留遍历到目前位可能的最远值
            far = max(far, nums[i] + i);
            // 如果最远值大等于数组结尾，立即返回true
            if (far >= nums.size() - 1)
                return true;
        }
        // 循环退出证明far一定小于数组结尾，所以i一定小于nums.size()-1,不会stackoverflow
        return false;
    }
};
// 尝试设计一个start把复杂度降低至O(2n)失败了
class Solution
{

public:
    bool canJump(vector<int> &nums)
    {
        vector<int> zero_pos{};
        if (nums.size() == 1)
            return true;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                zero_pos.push_back(i);
        }
        if (zero_pos.size() == 0)
            return true;
        bool result = false;
        // ⚠️设置start看似能将复杂度降低为o(n),但无法处理[4,2,0,0,1,1,4,4,4,0,4,0]这种两个0挨着的情况，必须从头开始尝试
        //  int start = 0;
        for (int i = 0; i < zero_pos.size(); i++)
        {
            result = false;
            // for (int j = start; j < zero_pos[i]; j++)
            for (int j = 0; j < zero_pos[i]; j++)
            {
                // 若直接大等于j开始到最后的距离，直接返回true
                if (nums[j] >= nums.size() - 1 - j)
                    return true;
                // 若有一个值大于过0的位置，则证明可以到下一段
                if (nums[j] > zero_pos[i] - j)
                {
                    result = true;
                    break;
                }
            }
            // 若此轮没有值大于此轮的0，则无论如何都到不了下一轮了，结果为false
            if (result == false)
                return false;

            // start = zero_pos[i] + 1;
        }
        return result;
    }
};

// 正确解但效率低
class Solution
{

public:
    bool canJump(vector<int> &nums)
    {
        vector<int> zero_pos{};
        if (nums.size() == 1)
            return true;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                zero_pos.push_back(i);
        }
        if (zero_pos.size() == 0)
            return true;
        bool result = false;

        for (int i = 0; i < zero_pos.size(); i++)
        {
            result = false;
            for (int j = 0; j < zero_pos[i]; j++)
            {
                // 若直接大等于j开始到最后的距离，直接返回true
                if (nums[j] >= nums.size() - 1 - j)
                    return true;

                // 若有一个值大于过0的位置，则证明可以到下一段// 若有一个值大于过0的位置，则证明可以到下一段
                if (nums[j] > zero_pos[i] - j)
                {
                    result = true;
                    break;
                }
            }
            // 若此轮没有值大于此轮的0，则无论如何都到不了下一轮了，结果为false
            if (result == false)
                return false;
        }
        return result;
    }
};