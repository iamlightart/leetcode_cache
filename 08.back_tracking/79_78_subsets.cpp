// https://leetcode.cn/problems/subsets/
#include <iostream>
using namespace std;
// 自己观察出了一种组合性质。。。用两层for解决了没有用回溯
// file://./imgs/79_78_subsets.jpg
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        subImpl(nums);
        results.push_back(vector<int>{});
        return results;
    }

private:
    vector<vector<int>> results;
    void subImpl(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (results.size() != 0)
            {
                int prev_length = results.size();
                for (int j = 0; j < prev_length; j++)
                {
                    vector<int> temp = results[j];
                    temp.push_back(nums[i]);
                    results.push_back(temp);
                }
                results.push_back(vector<int>{nums[i]});
            }
        }
    };
};
// 思路错了
class WrongSolution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        subImpl(nums, 0);
        results.push_back(vector<int>{});
        return results;
    }

private:
    vector<vector<int>> results;
    void subImpl(vector<int> &nums, int start)
    {
        if (start > nums.size())
            return;
        for (int i = start; i < nums.size(); i++)
        {
            vector<int> sub_vec(nums.begin() + start, nums.begin() + i + 1);
            results.push_back(sub_vec);
        }
        subImpl(nums, start + 1);
    }
};