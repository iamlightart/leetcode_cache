#include <iostream>
#include <vector>
using namespace std;
// https://leetcode.cn/problems/squares-of-a-sorted-array/
// 2025-11-10
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        if (nums.size() == 0)
            return nums;
        // 初始化不能写 int left , right = 0; 这样left会被附上垃圾值
        int left = 0, right = 0;
        // while条件要注意right < nums.size() 否则判断时可能会越界
        while (right < nums.size() && nums[right] < 0)
            right++;
        for (auto &num : nums)
            num *= num;
        if (right == 0 || left == nums.size() - 1)
            return nums;
        else if (right >= nums.size())
        {
            vector<int> result;
            for (int i = nums.size() - 1; i >= 0; i--)
            {
                result.push_back(nums[i]);
            }
            return result;
        }
        else
        {
            left = right - 1;
            vector<int> result;
            for (int i = 0; i < nums.size(); i++)
            {
                if (right >= nums.size())
                {
                    result.push_back(nums[left]);
                    left--;
                }
                else if (left < 0)
                {
                    result.push_back(nums[right]);
                    right++;
                }
                else if (nums[left] > nums[right])
                {
                    result.push_back(nums[right]);
                    right++;
                }

                else if (nums[left] <= nums[right])
                {
                    result.push_back(nums[left]);
                    left--;
                }
            }
            return result;
        }
    }
};