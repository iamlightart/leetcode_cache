// https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/
#include <iostream>
using namespace std;
// gpt的压缩解，尽可能多的反转负数，加和修改后所有值，存了最小绝对值，
// 如果负数都反转完了还剩基数次反转即直接将最小绝对值取反加入结果，影响最小（也就是减二次）
class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int sum = 0;
        int min_abs = INT_MAX;

        for (int &x : nums)
        {
            if (x < 0 && k > 0)
            {
                x = -x;
                k--;
            }
            sum += x;
            min_abs = min(min_abs, abs(x));
        }

        // 如果还剩奇数次翻转
        if (k % 2 == 1)
            sum -= 2 * min_abs;

        return sum;
    }
};
// 拆开反转和相加做得到了正确的结果，但感觉很奇怪这题应该不是个简单题？
class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (k == 0)
                break;
            // nums[i]<0
            if (nums[i] < 0)
            {
                if (i < nums.size() - 1)
                {
                    nums[i] = -nums[i];
                    k--;
                }
                if (i == nums.size() - 1)
                {
                    while (k > 0)
                    {
                        nums[i] = -nums[i];
                        k--;
                    }
                }
            }
            // nums[i]>=0
            else
            {
                int q = 0;
                if (i > 0)
                    q = nums[i] > nums[i - 1] ? i - 1 : i;
                while (k > 0)
                {
                    nums[q] = -nums[q];
                    k--;
                }
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        return sum;
    }
};
// 思路不对，[-8,3,-5,-3,-5,-2]处理不了，应该用3反转两次，而非-2和3各反转1次
class WrongSolution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int count = k;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count > 0)
            {
                if (nums[i] < 0)
                {
                    if (i < nums.size() - 1)
                    {
                        sum += -nums[i];
                        count--;
                    }
                    if (i == nums.size() - 1)
                    {
                        while (count > 0)
                        {
                            nums[i] = -nums[i];
                            count--;
                        }
                        sum += nums[i];
                    }
                }
                else
                {
                    while (count > 0)
                    {
                        nums[i] = -nums[i];
                        count--;
                    }
                    sum += nums[i];
                }
            }
            else
                sum += nums[i];
        }
        return sum;
    }
};