#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.cn/problems/remove-element/description/
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int current = 0;
        int tail = -1;
        while (current < nums.size())
        {
            if (nums[current] != val)
            {
                nums[tail + 1] = nums[current];
                tail++;
                current++;
            }
            else
            {
                current++;
            }
        }
        // 返回值是长度，要+1
        return tail + 1;
    }
};