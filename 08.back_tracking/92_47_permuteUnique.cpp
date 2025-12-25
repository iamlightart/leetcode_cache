// https://leetcode.cn/problems/permutations-ii/
#include <iostream>
#include <unordered_set>
using namespace std;
// 用排序后递归效率更高，不用频繁开销建立set，但要注意used[i - 1] == true的过滤比较巧妙
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        permuteImpl(nums, used);
        return results;
    }

private:
    vector<int> result;
    vector<vector<int>> results;
    void permuteImpl(vector<int> &nums, vector<bool> &used)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            // ⚠️used[i - 1] == true 只有可能是上面的某个递归层已用过了这个值，当前层如果用过会还原为false，满足跳过条件
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
                continue;
            if (used[i] == false)
            {
                result.push_back(nums[i]);
                if (result.size() == nums.size())
                    results.push_back(result);
                used[i] = true;
                permuteImpl(nums, used);
                result.pop_back();
                used[i] = false;
            }
        };
    }
};
// 解法慢，排序后过滤效率更快
class SlowSolution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false);
        permuteImpl(nums, used);
        return results;
    }

private:
    vector<int> result;
    vector<vector<int>> results;
    void permuteImpl(vector<int> &nums, vector<bool> &used)
    {
        unordered_set<int> layer_hodor{};
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i] == false && !layer_hodor.count(nums[i]))
            {
                layer_hodor.insert(nums[i]);
                result.push_back(nums[i]);
                if (result.size() == nums.size())
                    results.push_back(result);
                used[i] = true;
                permuteImpl(nums, used);
                result.pop_back();
                used[i] = false;
            }
        };
    }
};