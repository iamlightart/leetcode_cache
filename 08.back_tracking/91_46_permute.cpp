// https://leetcode.cn/problems/permutations/
#include <iostream>
#include <unordered_set>
using namespace std;
// 用vector<bool>来记录使用过的位置效率更高
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false);
        permuteImpl(nums, used);
        return results;
    }

private:
    vector<vector<int>> results;
    vector<int> result;

    void permuteImpl(vector<int> &nums, vector<bool> &used)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i] == false)
            {
                used[i] = true;
                result.push_back(nums[i]);
                if (result.size() == nums.size())
                    results.push_back(result);
                permuteImpl(nums, used);
                result.pop_back();
                used[i] = false;
            }
        };
    }
};
// 效率偏低
class SlowSolution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        permuteImpl(nums, 0);
        return results;
    }

private:
    vector<vector<int>> results;
    vector<int> result;
    unordered_set<int> used{};

    void permuteImpl(vector<int> &nums, int start)
    {
        for (int i = start; i < nums.size(); i++)
        {
            if (!used.count(nums[i]))
            {
                used.insert(nums[i]);
                result.push_back(nums[i]);
                if (result.size() == nums.size())
                    results.push_back(result);
                permuteImpl(nums, start);
                result.pop_back();
                used.erase(nums[i]);
            }
        };
    }
};