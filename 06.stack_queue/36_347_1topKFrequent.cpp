// https://leetcode.cn/problems/top-k-frequent-elements/
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
// 写了一个复杂度偏高的方法，暂时没想到更好的方法
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // 去重存储个数
        unordered_map<int, int> m{};
        for (int i : nums)
        {
            m[i]++;
        }
        // 反向存储自动排序
        multimap<int, int> reverse{};
        for (auto c : m)
        {
            // 插入需要花括号{int_1,int_2}
            reverse.insert({c.second, c.first});
        }
        // 输出需要子集
        vector<int> results{};
        int count = reverse.size();
        for (auto c : reverse)
        {
            if (count > k)
            {
                count--;
                continue;
            }
            results.push_back(c.second);
            // count--;开始push了count可以不用操作了
        }
        return results;
    }
};