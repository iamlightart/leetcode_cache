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
// 桶排序方法，理论最优
//  top-k 是在“频率全序集”上的一个截断（truncation）映射，
//   当第二名出现频率不唯一时，截断结果不是函数，而是一个多值函数。
//  比如1出现了8次，3和4出现了7次，k=2,返回[1,3]或[1,4]或[3,1]或[4,1]都正确
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
        // 首先bucket要初始化，不然会访问异常
        // nums.size()+1方式很巧妙：通过+1，把所有的次数都可以和buckets的大小对齐，不用在后面做offsite的调整
        // nums有多少数，极限情况都是一个数，那这个数出现的次数也就是nums.size()+1,不可能更大
        vector<vector<int>> buckets{nums.size() + 1};
        for (auto c : m)
        {
            buckets[c.second].push_back(c.first);
        }
        int count = 0;
        vector<int> result{};

        // // for可以优化一下从最高往下扫
        // for (vector<int> bucket : buckets)
        // {
        //     for (int unit : bucket)
        //     {

        //         if (count < m.size() - k)
        //         {
        //             count++;
        //             continue;
        //         }
        //         else
        //         {
        //             result.push_back(unit);
        //         }
        //     };
        // }

        // buckets中从高往下扫
        for (int freq = buckets.size() - 1; freq >= 0; freq--)
        {
            for (int i = 0; i < buckets[freq].size(); i++)
            {
                result.push_back(buckets[freq][i]);
                count++;
                // 也可以用result.size()==k 来判断，因为vector插入时内部计数器已经完成计算
                if (count == k)
                    return result;
            }
        }
        return result;
    }
};