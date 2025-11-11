#include <iostream>
#include <vector>
using namespace std;
// https: // leetcode.cn/problems/minimum-size-subarray-sum/description/
// 2025-11-11
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int win_size = INT32_MAX, l = 0, r = 0;
        int curr_sum = 0;
        while (r < nums.size())
        {
            curr_sum += nums[r];
            // 注意窗口前进后，应该从左弹出，同时保留遍历途中的所有最小值，才能包含所有解
            while (curr_sum >= target)
            {
                // 每添加一个右值，相当于延长了要测试的数组，而比较的值是之前少一位数组的最小值
                win_size = min(win_size, r - l + 1);
                curr_sum -= nums[l];
                l++;
            }
            r++;
        }
        // 结果要处理curr_sum始终小于target的情况
        return win_size != INT32_MAX ? win_size : 0;
    }
};

int main()
{
    vector<int> input = {3, 1, 8, 2};
    Solution s;
    cout << s.minSubArrayLen(10, input) << endl;
}

////// 下面是错误思路，从两边弹，但这样会导致测试覆盖不全
// target = 10，nums = [3, 1, 8, 2] 不能弹尾部，相当于数组不包含后面的值，会导致覆盖不全的问题，本来结果是2，弹尾巴会为3
class WrongSolution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        deque<int> window;
        int current_sum = 0;
        int min_size = 0;
        for (auto num : nums)
        {
            if (num >= target)
            {
                while (!window.empty())
                    window.pop_front();
                window.push_back(num);
                current_sum = num;
            }
            else
            {
                window.push_back(num);
                current_sum += num;
            }
        }

        if (current_sum < target)
            return 0;

        while (current_sum >= target)
        {
            if (window.size() == 1)
                return 1;
            if (window.front() <= window.back())

            {
                current_sum -= window.front();
                window.pop_front();
            }
            else
            {
                // 从右弹出会导致测试覆盖不全，弹出右边的值后，接下来的测试相当于在没有右值的数组中进行测试
                current_sum -= window.back();
                window.pop_back();
            }
        }

        return window.size() + 1;
    }
};

int wrong_main()
{
    vector<int> input = {3, 1, 8, 2};
    WrongSolution s;
    cout << s.minSubArrayLen(10, input) << endl;
    return 0;
}