// https://leetcode.cn/problems/unique-binary-search-trees/
#include <iostream>
using namespace std;
// 100%ac!很棒
class Solution
{
public:
    vector<int> hodor{};
    int numTrees(int n)
    {
        // ⚠️处理n=1的特殊值，后面的值都是按照n>=2来设计的
        if (n == 1)
            return 1;
        hodor.resize(n + 1, 0);
        hodor[1] = 1;
        hodor[2] = 2;
        for (int i = 3; i < hodor.size(); i++)
        {
            hodor[i] += hodor[i - 1];
            for (int j = 1; j < i; j++)
            {
                hodor[i] += hodor[j] * hodor[i - j - 1];
            }
            hodor[i] += hodor[i - 1];
        }
        return hodor[n];
    }
};