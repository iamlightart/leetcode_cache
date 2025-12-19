// https://leetcode.cn/problems/combination-sum-ii/
#include <iostream>
#include <math.h>
#include <set>
using namespace std;
// 循环中的每一步的值，如果i>start，相当于这个数在这个位置已经用过一次了，是可以跳过的
class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        combImpl(candidates, target, 0);
        return results;
    }

private:
    vector<vector<int>> results;
    vector<int> result;
    int temp;
    void combImpl(vector<int> &candidates, int target, int start)
    {
        for (int i = start; i < candidates.size(); i++)
        {
            if (i > start && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            else
            {
                temp += candidates[i];
                result.push_back(candidates[i]);
                if (temp == target)
                    results.push_back(result);
                if (temp < target)
                    combImpl(candidates, target, i + 1);
                // TODO  不要乱 if(temp>target) break; 结合上一题的TOOD评估 return和break的节点
                temp -= candidates[i];
                result.pop_back();
            }
        }
    }
};

// 此方法在重复输入情况下超时 ,比如100个1 得到结果30
class SlowSolution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        combImpl(candidates, target, 0);
        return vector<vector<int>>(results.begin(), results.end());
    }

private:
    set<vector<int>> results;
    // unordered_set 的底层依赖「哈希函数」，但 C++ 标准库没有为 vector<int> 提供默认的哈希函数 —— 编译器无法计算 vector<int> 的哈希值，
    // 因此 unordered_set<vector<int>> 的默认构造函数被隐式删除。
    // 用set
    vector<int> result;
    int temp;
    void combImpl(vector<int> &candidates, int target, int start)
    {
        for (int i = start; i < candidates.size(); i++)
        {
            temp += candidates[i];
            result.push_back(candidates[i]);
            if (temp == target)
                results.insert(result);
            if (temp < target)
                // 不要在递归时犯传错值的错误，是i+1不是start+1！
                combImpl(candidates, target, i + 1);
            temp -= candidates[i];
            result.pop_back();
        }
    }
};

int main()
{
    vector<int> a = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    cout << a.size();
}