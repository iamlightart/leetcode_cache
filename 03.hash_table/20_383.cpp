// https://leetcode.cn/problems/ransom-note/description/
// 2025-11-17
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        // 用char对应的ascii int可以更快的处理问题，用unordered_map只有57%，用数组100%
        // 数字4857 大写6590 小写97122
        // char取值范围0-127，hodor[128]刚好覆盖所有可能
        int hodor[128] = {0};
        // unordered_map<char, int> hodor;
        // hodor.reserve(magazine.size());
        for (auto c : magazine)
        {
            hodor[c]++;
        }
        for (auto c : ransomNote)
        {
            if (hodor[c] == 0)
                return false;
            hodor[c]--;
        }
        return true;
    }
};