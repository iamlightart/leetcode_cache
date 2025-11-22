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
    // 编码能力还是有问题，字符串后面两道题要重点重做
    // ChatGPT说我现在已经抓住了最难的部分：
    // ✔ 要构造 next 数组
    // ✔ 用 next[n-1] 代表最长公共前后缀长度
    // ✔ 通过 n - next[n-1] 判断重复周期
    // ✔ 子串要重复拼接检查
    // 你的整体路线几乎就是标准 KMP 做法了。
    bool repeatedSubstringPattern(string s)
    {
        if (s.size() == 0)
            return false;
        if (s.size() == 1)
            return true;
        vector<int> next{};
        // reserve()没有占用只是开辟空间，resize才会按需求数量用0填充vector
        next.resize(s.size());
        cout << next.size() << endl;
        // 构造next数组
        int i = 0, j = 1;
        while (j < s.size())
        {
            if (s[j] == s[i])
            {
                next[j] = next[j - 1] + 1;
            }
            else
            {
                i = next[next[j - 1]];
                if (s[j] == s[i])
                {
                    next[j] = i + 1;
                }
                else
                {
                    next[j] = 0;
                }
            }
            i++;
            j++;
        }

        for (auto c : next)
        {
            cout << c << ",";
        }

        // int sub = s.size() - next[s.size() - 1];
        // cout << sub << endl;

        // string temp = s.substr(0, sub);
        // cout << temp;
        // if (temp.size() > s.size() / 2)
        //     return false;
        // else
        // {
        //     // 上面构造next数组时候用了i，如果再用i，for循环内部会使用上面定义的i
        //     for (int k = temp.size(); k < s.size(); k += temp.size())
        //     {
        //         if (temp != s.substr(k, min(s.size() - k, temp.size())))
        //             return false;
        //     }
        // }

        return true;
    }
};
int main()
{
    Solution s;
    cout << boolalpha << s.repeatedSubstringPattern("abacabab");
}
// 暴力法一次通过测试，但是效率非常低只有5%
// class deprecatedSolution
// {
// public:
//     bool repeatedSubstringPattern(string s)
//     {
//         bool result = false;

//         for (int i = 0; i < s.size() / 2; i++)
//         {
//             string temp = s.substr(0, 1 + i);
//             for (int j = i + 1; j < s.size(); j += temp.size())
//             {
//                 result = true;
//                 if (s[j] != temp[0])
//                 {
//                     result = false;
//                     break;
//                 }
//                 else if (temp != s.substr(j, temp.size()))
//                 {
//                     result = false;
//                     break;
//                 }
//             }
//             if (result)
//                 break;
//         }

//         return result;
//     }
// };

// 不能只考虑三等分，还有各种2n+1的等分，这样是错误的
// class WrongSolution
// {
// public:
//     bool repeatedSubstringPattern(string s)
//     {
//         // 这个判断不对，abcabcabc会出错
//         // if (s.size() == 0 || s.size() % 2 != 0)
//         // return false;
//         bool odd_check = true;
//         bool even_check = true;
//         bool is_odd = s.size() / 2 % 2;

//         if (!is_odd)
//             odd_check = false;
//         else
//         {
//             int tri_idx_1 = s.size() / 3;
//             int tri_idx_2 = s.size() / 3 * 2;
//             for (int i = 0; i < tri_idx_1; i++)
//             {
//                 // 注意break的位置，之前写在外面导致了提前中断
//                 if (s[i] != s[tri_idx_1 + i] || s[tri_idx_1 + i] != s[tri_idx_2 + i] || s[i] != s[tri_idx_2 + i])
//                 {
//                     odd_check = false;
//                     break;
//                 }
//             }
//         }

//         {
//             int half_idx = s.size() / 2;
//             for (int i = 0; i < half_idx; i++)
//             {
//                 cout << s[i] << ":" << s[half_idx + i] << endl;
//                 if (s[i] != s[half_idx + i])
//                 {
//                     even_check = false;
//                     break;
//                 }
//             }
//         }
//         cout << odd_check << even_check << endl;
//         return odd_check || even_check;
//     }
// };
