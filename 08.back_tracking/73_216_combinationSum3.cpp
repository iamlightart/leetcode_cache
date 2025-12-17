// https://leetcode.cn/problems/combination-sum-iii/
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        combImpl(k, n, 1);
        return results;
    }

private:
    vector<vector<int>> results;
    vector<int> result_hodor;
    // 用curr_sum在递归路径中存储已经得到的加和部分，可以减少重复计算
    int curr_sum = 0;
    void combImpl(int counts, int n, int start)
    {
        if (counts == 0)
        {
            if (curr_sum == n)
                results.push_back(result_hodor);
            return;
        }
        // 组合n的k只能是≤9,最大值不是n - counts + 1!别弄错了否则会超时！
        for (int i = start; i <= 9; i++)
        {
            curr_sum += i;
            result_hodor.push_back(i);
            // ⚠️注意！递归进去的时候，不是start+1 而是 i+1
            combImpl(counts - 1, n, i + 1);
            curr_sum -= i;
            result_hodor.pop_back();
        }
    }
};