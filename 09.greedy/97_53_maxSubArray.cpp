// https://leetcode.cn/problems/maximum-subarray/
#include <iostream>
using namespace std;

class Solution
{
public:
    // 更优雅的解，需要best存一道值，不然中间的最大解会被错过，比如[-2,1,-3,4,-1,2,1,-5,4]
    int maxSubArray(vector<int> &nums)
    {
        int temp = nums[0];
        int best = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            temp = max(nums[i], temp + nums[i]);
            best = max(best, temp);
        }

        return best;
    }
};

// 按gpt说可以压缩condition
class MySolution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        bool all_neg = true;
        int pot_min = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                all_neg = false;
                break;
            }

            if (nums[i] <= 0 && nums[i] > pot_min)
                pot_min = nums[i];
        }
        if (all_neg)
            return pot_min;

        int temp = 0;
        int max = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            temp += nums[i];
            if (temp > max)
                max = temp;
            if (temp < 0)
                temp = 0;
        }
        return max;
    }
};