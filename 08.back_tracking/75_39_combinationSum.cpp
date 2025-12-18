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
            if (temp == target)
                results.push_back(result);
            else if (temp < target)
                combinationImpl(candidates, target, i);
            temp -= candidates[i];
            result.pop_back();
        }
    }
};