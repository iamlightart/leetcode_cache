#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.cn/problems/binary-search/
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        return binary_search(nums, target, 0, nums.size() - 1);
    }

    int binary_search(vector<int> &nums, int target, int start, int end)
    {
        if (start > end)
            return -1;
        // 中点值不是 (end - start) / 2;
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
            return mid;
        else
        {
            if (nums[mid] > target)
                return binary_search(nums, target, start, mid - 1);
            else if (nums[mid] < target)
                return binary_search(nums, target, mid + 1, end);
        }
        return -1;
    }
};