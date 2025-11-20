// https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/
//  2025-11-20
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
// KMP算法效率O(m+n)
// KMP就是把输入字符串的每一个子串，计算首尾相等的长度然后存起来，匹配的时候遇到不一样的值，则只挪动过的长度

// ✅标准答案
// class Solution
// {
// public:
//     // 构造前缀表（next 数组）
//     vector<int> buildNext(const string &pattern)
//     {
//         int m = pattern.size();
//         vector<int> nxt(m, 0);
//         int j = 0; // 已匹配的前缀长度

//         // i 从 1 开始扫描（nxt[0] 恒为 0）
//         for (int i = 1; i < m; i++)
//         {
//             // 如果不匹配，回退
//             while (j > 0 && pattern[i] != pattern[j])
//             {
//                 j = nxt[j - 1];
//             }
//             // 如果匹配，增加匹配长度
//             if (pattern[i] == pattern[j])
//             {
//                 j++;
//             }
//             nxt[i] = j;
//         }

//         return nxt;
//     }

//     // KMP 主算法：返回 pattern 在 text 中首次出现的位置
//     int strStr(string text, string pattern)
//     {
//         if (pattern.empty())
//             return 0;

//         vector<int> nxt = buildNext(pattern);
//         int j = 0;

//         for (int i = 0; i < (int)text.size(); i++)
//         {
//             while (j > 0 && text[i] != pattern[j])
//             {
//                 j = nxt[j - 1];
//             }
//             if (text[i] == pattern[j])
//             {
//                 j++;
//             }
//             if (j == pattern.size())
//             {
//                 return i - j + 1; // 完整匹配
//             }
//         }
//         return -1;
//     }
// };

// ⚠️我目前的做法从复杂度上来看时极其错误的，没有理解kmp的核心，需要进一步学习一下，这个解复杂度已经是o(n³)
class Solution
{
public:
    vector<int> calc_kmp(string &needle)
    {
        vector<int> kmp(needle.size(), 0);
        for (int length = 1; length <= needle.size(); length++)
        {
            string temp = needle.substr(0, length);
            if (temp.size() == 1)
            {
                kmp[0] = 0;
            }
            else
            {
                for (int i = 0; i < temp.size() - 1; i++)
                {
                    string start = temp.substr(0, i + 1);
                    // 这里求解好绕，我只通过举例才列出来了
                    string end = temp.substr(temp.size() - 1 - i, i + 1);
                    if (start == end)
                        kmp[temp.size() - 1] = start.size();
                }
            }
        }
        return kmp;
    }
    int strStr(string haystack, string needle)
    {
        vector<int> kmp = calc_kmp(needle);
        int start = 0;
        while (start + needle.size() - 1 <= haystack.size() - 1)
        {
            // cout << "start:" << start << endl;
            bool finished = true;
            for (int i = 0; i < needle.size(); i++)
            {

                if (needle[i] != haystack[start + i])
                {
                    start = i == 0 ? start + 1 : start + i - kmp[i - 1];
                    finished = false;
                    break;
                }
            }
            if (finished)
                return start;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    cout << "result: " << s.strStr("aabaabaaf", "aabaaf") << endl;
    cout << "result: " << s.strStr("abcabc", "abc") << endl;
    cout << "result: " << s.strStr("dabcabc", "abc") << endl; // 用haystack来做kmp会出现漏解，因为start是needle而非haystack
    cout << "result: " << s.strStr("leetcode", "leeto") << endl;
    cout << "result: " << s.strStr("hello", "ll") << endl;
    cout << "result: " << s.strStr("abbabaaaabbbaabaabaabbbaaabaaaaaabbbabbaabbabaabbabaaaaababbabbaaaaabbbbaaabbaaabbbbabbbbaaabbaaaaababbaababbabaaabaabbbbbbbaabaabaabbbbababbbababbaaababbbabaabbaaabbbba", "bbbbbbaa") << endl;
}

// ❌不应该用haystack来匹配前后缀，因为前后缀是以needle为头的，如果以stack为头就只匹配了与stack头相等的串
// class Solution
// {
// public:
//     vector<int> calc_kmp(string &haystack)
//     {
//         vector<int> kmp(haystack.size(), 0);
//         for (int length = 1; length <= haystack.size(); length++)
//         {
//             string temp = haystack.substr(0, length);
//             if (temp.size() == 1)
//             {
//                 kmp[0] = 0;
//             }
//             else
//             {
//                 for (int i = 0; i < temp.size() / 2; i++)
//                 {
//                     string start = temp.substr(0, i + 1);
//                     // 这里求解好绕，我只通过举例才列出来了
//                     string end = temp.substr(temp.size() - 1 - i, i + 1);
//                     if (start == end)
//                         kmp[temp.size() - 1] = start.size();
//                 }
//             }
//         }
//         cout << "kmp:[";
//         for (auto i : kmp)
//             cout << i << ',';
//         cout << "]" << endl;
//         return kmp;
//     }
//     int strStr(string haystack, string needle)
//     {
//         vector<int> kmp = calc_kmp(haystack);
//         int start = 0;
//         while (start + needle.size() - 1 <= haystack.size() - 1)
//         {
//             bool finished = true;
//             for (int i = 0; i < needle.size(); i++)
//             {

//                 if (needle[i] != haystack[start + i])
//                 {
//                     start = start + i - kmp[i - 1];
//                     finished = false;
//                     break;
//                 }
//             }
//             if (finished)
//                 return start;
//         }

//         return -1;
//     }
// };

// int main()
// {
//     Solution s;
//     cout << "result: " << s.strStr("aabaabaaf", "aabaaf") << endl;
//     cout << "result: " << s.strStr("abcabc", "abc") << endl;
//     cout << "result: " << s.strStr("dabcabc", "abc") << endl; // 用haystack来做kmp会出现漏解，因为start是needle而非haystack
//     cout << "result: " << s.strStr("leetcode", "leeto") << endl;
// }

// ⚠️ 简单解 相当于是暴力解 复杂度O(m*n)
// class MySolution
// {
// public:
//     int checkWord(string haystack, string needle, int start)
//     {
//         if (haystack.size() - start < needle.size())
//             return -1;
//         else
//         {
//             for (size_t i = 0; i < needle.size(); i++)
//             {
//                 if (haystack[start + i] != needle[i])
//                     return -1;
//             }
//         }

//         return start;
//     }
//     int strStr(string haystack, string needle)
//     {
//         int result = -1;
//         for (int i = 0; i < haystack.size(); i++)
//         {
//             if (haystack[i] == needle[0])
//                 result = checkWord(haystack, needle, i);
//             if (result != -1)
//                 return result;
//         }
//         return result;
//     }
// };