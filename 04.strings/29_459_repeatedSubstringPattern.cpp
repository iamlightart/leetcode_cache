// https://leetcode.cn/problems/repeated-substring-pattern/
//  2025-11-22
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
    bool repeatedSubstringPattern(string s)
    {
        bool is_odd = false;
        if (s.size() % 2 || s.size() / 2 % 2)
            is_odd = true;
        if (is_odd)
        {
        }
        else
        {
            // 这样判断偶数解是最快的，但没办法处理奇数解 (长度为奇数，或重复为奇数)
            int half_idx = s.size() / 2;
            for (int i = 0; i < half_idx; i++)
            {
                if (s[i] != s[half_idx + i])
                {
                    return false;
                }
            }
            return true;
        }
    }
};
// 暴力法一次通过测试，但是效率非常低只有5%
class deprecatedSolution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        bool result = false;

        for (int i = 0; i < s.size() / 2; i++)
        {
            string temp = s.substr(0, 1 + i);
            for (int j = i + 1; j < s.size(); j += temp.size())
            {
                result = true;
                if (s[j] != temp[0])
                {
                    result = false;
                    break;
                }
                else if (temp != s.substr(j, temp.size()))
                {
                    result = false;
                    break;
                }
            }
            if (result)
                break;
        }

        return result;
    }
};

// 不能只考虑三等分，还有各种2n+1的等分，这样是错误的
class WrongSolution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        // 这个判断不对，abcabcabc会出错
        // if (s.size() == 0 || s.size() % 2 != 0)
        // return false;
        bool odd_check = true;
        bool even_check = true;
        bool is_odd = s.size() / 2 % 2;

        if (!is_odd)
            odd_check = false;
        else
        {
            int tri_idx_1 = s.size() / 3;
            int tri_idx_2 = s.size() / 3 * 2;
            for (int i = 0; i < tri_idx_1; i++)
            {
                // 注意break的位置，之前写在外面导致了提前中断
                if (s[i] != s[tri_idx_1 + i] || s[tri_idx_1 + i] != s[tri_idx_2 + i] || s[i] != s[tri_idx_2 + i])
                {
                    odd_check = false;
                    break;
                }
            }
        }

        {
            int half_idx = s.size() / 2;
            for (int i = 0; i < half_idx; i++)
            {
                cout << s[i] << ":" << s[half_idx + i] << endl;
                if (s[i] != s[half_idx + i])
                {
                    even_check = false;
                    break;
                }
            }
        }
        cout << odd_check << even_check << endl;
        return odd_check || even_check;
    }
};
