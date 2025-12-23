// https://leetcode.cn/problems/non-decreasing-subsequences/
#include <iostream>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        findImpl(nums, 0);
        return results;
    }

private:
    vector<int> result;
    vector<vector<int>> results;

    void findImpl(vector<int> &nums, int start)
    {
        if (start >= nums.size())
            return;
        unordered_set<int> used;
        for (int i = start; i < nums.size(); i++)
        {
            // 不能用i>start的方式过滤，这样会导致[...1....1,1,1,1] 这样的题解，两次统计[1,1],[1,1,1]...类似的结果
            // i>start只能用于已排序的场景
            // if (i > start && nums[i] == nums[i - 1])
            //     continue;
            // 用set对于本层中已经用过在开头的值进行去重，从而得到正确的结果
            if (used.count(nums[i]))
                continue;
            if (result.size() == 0 || nums[i] >= result[result.size() - 1])
            {
                used.insert(nums[i]);
                result.push_back(nums[i]);
                if (result.size() >= 2)
                    results.push_back(result);
                findImpl(nums, i + 1);
                result.pop_back();
            }
        }
    }
};

int main()
{
    vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 1, 1, 1, 1};
    Solution s;
    vector<vector<int>> result = s.findSubsequences(input);
    for (auto c : result)
    {
        cout << "[";
        for (int i = 0; i < c.size(); i++)
        {
            cout << c[i];
            if (i != c.size() - 1)
                cout << ",";
        }
        cout
            << "],";
    }
}
