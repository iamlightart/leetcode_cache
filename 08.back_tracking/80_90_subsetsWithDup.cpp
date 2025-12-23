// https://leetcode.cn/problems/subsets-ii/s
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        results.push_back(result);
        subImpl(nums, 0);
        return results;
    }

private:
    vector<vector<int>> results;
    vector<int> result;
    void subImpl(vector<int> &nums, int start)
    {
        for (int i = start; i < nums.size(); i++)
        {
            // 每个位置相同的值只用一次，后面重复的跳过
            if (i > start && nums[i] == nums[i - 1])
                continue;
            result.push_back(nums[i]);
            results.push_back(result);
            subImpl(nums, i + 1);
            result.pop_back();
        }
    }
};

int main()
{
    Solution s;
    vector<int> test_input = {1, 3, 2, 2, 4};
}