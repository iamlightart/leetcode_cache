// https://leetcode.cn/problems/reverse-string/
// 2025-11-19
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int end = s.size() - 1;
        for (int i = 0; i < s.size() / 2; i++)
        {
            char temp = s[i];
            s[i] = s[end - i];
            s[end - i] = temp;
        }
    }
};