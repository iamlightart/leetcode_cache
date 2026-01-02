// https://leetcode.cn/problems/queue-reconstruction-by-height/description/
#include <iostream>
#include <map>
using namespace std;
class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        vector<vector<int>> results;
        // ⚠️lambda排序，传函数boo comp(..) 进sort均可，java1.8后可以用lambda，1.8之前用comparator
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b)
             {
        if (a[0] != b[0]) {
            return a[0] > b[0]; // 第一位降序
        } else {
            return a[1] < b[1]; // 第二位升序
        } });
        // 可以不用start。完全使用插入逻辑
        // int start = people[0][0];
        for (int i = 0; i < people.size(); i++)
        {
            // if (people[i][0] == start)
            // {
            //     results.push_back(people[i]);
            // }
            // else
            // {
            //     results.insert(results.begin() + people[i][1], people[i]);
            // }
            // 插入逻辑，vector可以根据begin()+offset来做插入
            results.insert(results.begin() + people[i][1], people[i]);
        };
        return results;
    }
};