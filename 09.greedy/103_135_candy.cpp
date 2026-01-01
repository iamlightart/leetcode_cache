// https://leetcode.cn/problems/candy/
#include <iostream>
#include <map>
using namespace std;
// 默写了一遍
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        vector<int> hodor(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
                // 因为默认值为1，左轮满足直接赋值需求，用max比较会降效率
                //  hodor[i] = max(hodor[i - 1] + 1, hodor[i]);
                hodor[i] = hodor[i - 1] + 1;
        }
        // 不要用size_t,反向索引会出问题，i--  →  下溢 →  i = SIZE_MAX，条件永远为真
        //  for (size_t i = ratings.size() - 2; i >= 0; i--)
        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
                hodor[i] = max(hodor[i + 1] + 1, hodor[i]);
        }
        int result = 0;
        for (auto c : hodor)
            result += c;
        return result;
    }
};
// gpt solution 双端扫描
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> candies(n, 1);

        // 左 -> 右：处理 ratings[i] > ratings[i-1]
        for (int i = 1; i < n; ++i)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // 右 -> 左：处理 ratings[i] > ratings[i+1]
        for (int i = n - 2; i >= 0; --i)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // 汇总
        int sum = 0;
        for (int c : candies)
            sum += c;
        return sum;
    }
};

// 效率不高，但是困难题自己做出来了
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        // multrimap保证排序和重复key
        multimap<int, int> val_pos{};
        vector<int> results(ratings.size(), 1);
        int result = 0;
        for (int i = 0; i < ratings.size(); i++)
        {
            // 插入multimap的语法
            val_pos.insert({ratings[i], i});
        }

        for (auto c : val_pos)
        {
            int curr_pos = c.second;
            int left_pos = c.second - 1 < 0 ? 0 : c.second - 1;
            int right_pos = c.second + 1 > ratings.size() - 1 ? ratings.size() - 1 : c.second + 1;
            // 根据multimap的结果来处理值
            // 当前rating数据比两边的数据大时
            if (ratings[curr_pos] > ratings[left_pos] && ratings[curr_pos] > ratings[right_pos])
            {
                // 左边result比当前大，则比左边大1
                if (results[left_pos] >= results[curr_pos])
                    results[curr_pos] = results[left_pos] + 1;
                // 右边result比当前大，则比右边大1
                if (results[right_pos] >= results[curr_pos])
                    results[curr_pos] = results[right_pos] + 1;
                // 两边result若都比当前小则不用操作
            }
            // 当前rating数据比两边小时
            else
            {
                // rating比左边小时
                if (ratings[curr_pos] < ratings[left_pos] && curr_pos != 0)
                {
                    // result比左边大，左边抬高到curr+1
                    if (results[left_pos] <= results[curr_pos])
                        results[left_pos] = results[curr_pos] + 1;
                }

                if (ratings[curr_pos] < ratings[right_pos] && curr_pos != ratings.size() - 1)
                {
                    // result比右边大，右边抬高到curr+1
                    if (results[right_pos] <= results[curr_pos])
                        results[right_pos] = results[curr_pos] + 1;
                }
            }
        }
        // 结果集加和返回值
        for (auto c : results)
        {
            result += c;
        }
        return result;
    }
};