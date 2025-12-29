// https://leetcode.cn/problems/wiggle-subsequence/
#include <iostream>
using namespace std;
// 状态压缩解，就是假设两个可能，第二个值是up/down，加好后比较长度，每次up+1，前面都是down；每次down+1，前面都是up
// 感觉不是很直观，但看一遍后可以理解
class GPTSolution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return n;

        int up = 1;   // 以“上升”结尾的最长摆动子序列长度
        int down = 1; // 以“下降”结尾的最长摆动子序列长度

        // 正确的摆动链，最长摆动链结尾为up，则最长的down一定是up-1,同理结尾down，最长的up一定是down-1
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
                up = down + 1; // 之前down结尾链长度加1，并替换为up
            else if (nums[i] < nums[i - 1])
                down = up + 1; // 之前up尾链长度+1，并更新为down
            // 相等时什么都不做
        }
        return max(up, down);
    }
};
// 我的解法
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 1;
        if (nums.size() == 2)
            return nums[0] == nums[1] ? 1 : 2;
        int start = 1;
        while (nums[start] == nums[start - 1] && start < nums.size() - 1)
            start++;
        if (start == nums.size() - 1)
            return 1;

        bool up = nums[start] > nums[start - 1] ? true : false;
        int prev = nums[start];
        int result = 2;
        for (int i = start + 1; i < nums.size(); i++)
        {
            if ((nums[i] < prev && up) || (nums[i] > prev && !up))
            {
                result++;
                up = !up;
            }

            prev = nums[i];
        }
        return result;
    }
};