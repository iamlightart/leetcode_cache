// https://leetcode.cn/problems/integer-break/
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> hodor{};
    int integerBreak(int n)
    {
        hodor.resize(n + 1, 0);
        hodor[1] = 1;
        hodor[2] = 1;
        for (int i = 3; i < hodor.size(); i++)
        {
            for (int j = 1; j <= i / 2; j++)
            {
                int val_1 = j;
                int val_2 = i - val_1;
                hodor[i] = max(max(val_1, hodor[val_1]) * max(val_2, hodor[val_2]), hodor[i]);
            }
        }
        return hodor[n];
    }
};