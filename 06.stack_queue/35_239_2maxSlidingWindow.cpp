// https://leetcode.cn/problems/sliding-window-maximum/description/
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <unordered_set>
using namespace std;
// 这题难点就是存状态，在目前的滑动窗口中，状态永远保持最大值在头部，后面的值单调递减
// Myqueue永远保持着窗口中的一个子集，这个子集以窗口的最大值为起点，最大值后面小于最大值的其他次大值单调递减
// 构建的myqueue和窗口的区别在于只存窗口中的降序列子集，相当于把当前的最大值挑了出来，只在窗口将当前最大值移出的时候才进行删除
class Myqueue
{
private:
    deque<int> hodor;

public:
    void insert(int temp)
    {
        // ⚠️ 如果deque为空时直接调用front()等访问元素函数，会产生segmentfault的报错
        if (!hodor.empty())
        {
            if (temp > hodor.front())
            {
                hodor.clear();
                hodor.push_back(temp);
            }
            else
            {
                while (hodor.back() < temp)
                {
                    hodor.pop_back();
                }
                hodor.push_back(temp);
            }
        }
        else
        {
            hodor.push_back(temp);
        }
    }
    int getMax()
    {
        return hodor.front();
    }
    void pop()
    {
        hodor.pop_front();
    }
};
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> result{};
        Myqueue q{};
        for (int i = 0; i < k; i++)
        {
            q.insert(nums[i]);
        }
        result.push_back(q.getMax());
        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i - k] == q.getMax())
                q.pop();
            q.insert(nums[i]);
            result.push_back(q.getMax());
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> input = {1, 3, -1, -3, 5, 3, 6, 7};
    input = s.maxSlidingWindow(input, 3);
    for (auto c : input)
    {
        cout << c << ",";
    };
}