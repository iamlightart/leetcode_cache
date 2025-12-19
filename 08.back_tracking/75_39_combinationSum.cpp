// https://leetcode.cn/problems/combination-sum/
#include <iostream>
using namespace std;
// ⚠️️️️️⚠️️️️️⚠️️️️️⚠️️️️️
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        combinationImpl(candidates, target, 0);
        return results;
    }

private:
    vector<vector<int>> results;
    vector<int> result;
    int temp = 0;
    void combinationImpl(vector<int> &candidates, int target, int start)
    {
        for (int i = start; i < candidates.size(); i++)
        {
            temp += candidates[i];
            result.push_back(candidates[i]);
            // TODO 起来研究一下，return的条件，尤其是前一面比如73——216的⚠️️️️️⚠️️️️️⚠️️️️️ 这道题里不能随便return了，注意做个类比
            // if (counts == 0)
            // {
            //     if (curr_sum == n)
            //         results.push_back(result_hodor);
            //     return;
            // }
            if (temp == target)
                results.push_back(result);
            else if (temp < target)
                combinationImpl(candidates, target, i);
            temp -= candidates[i];
            result.pop_back();
        }
    }
};