// https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/
//  2025-11-23
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
// KMP按照next数组会跳过一部分被模式串匹配的主串，保证被跳过这部分不存在更优解是因为：
// 假设匹配失败的点位m，则会根据next[m-1]来挪动模式串
// 首先，因为匹配失败而挪动模式串，匹配失败点m之前是模式串的一部分，长度必然小于模式串。
// 所以在匹配的过程中，如果存在比根据next[m-1]计算出的模式串头位置更好更靠左的点，
// 则这样匹配到next[m-1]时，next[m-1]该有的值一定是大于已存储的点的。但在构建next[m-1]时，已经找到next[m-1]的值，故结论不成立

class Solution
{
public:
    // 构建一个数值数组，存储字符串内，所有子字符串最短相同前后缀的长度
    vector<int> buildNext(const string &s)
    {
        // 构建空的，与传入字符串相同长度的数组，并用0填充
        vector<int> result(s.size(), 0);
        // 当数组长度为1，即字符串长度为1，直接返回
        if (result.size() == 1)
            return result;
        // 构建两个指针，i指向前缀的尾部，j指向后缀的尾部
        int i = 0, j = 1;
        while (j < s.size())
        {
            // 如果i，j位相等，即相同前后缀比较起之前的值，又各多了一位相等
            if (s[i] == s[j])
            {
                result[j] = result[j - 1] + 1;
                i++;
                j++;
            }
            else
            {
                // 新的一位不相等时，前缀指针，会按照前一位已匹配的最长相同前后缀长度，后退到前缀的下一位，
                // 比如上一个前缀匹配了3的长度，退回到下标3，正好是从第4位开始比较
                // 但最多后退到字符串第一位，否则越界
                while (s[i] != s[j] && i != 0)
                {
                    // 这里是i-1,前面已匹配序列的最长前后缀，之前写错成i了
                    i = result[i - 1];
                }
                // 当后退后相等时
                if (s[i] == s[j])
                {
                    // 新的最长相同长度，即是退回后的长度+1
                    result[j] = i + 1;
                    i++;
                    j++;
                }
                else
                {
                    // 如果推到了0也没有相等，就没有已经匹配的前缀了，新的后缀值也为0
                    result[j] = 0;
                    j++;
                }
            }
        };
        return result;
    }
    int strStr(string haystack, string needle)
    {
        // 处理边界值输入
        if (haystack.size() < needle.size())
            return -1;
        if (haystack.size() == needle.size())
            return haystack == needle ? 0 : -1;
        // 创建next数组，用来匹配haystack和needle
        vector<int> next = buildNext(needle);
        int i = 0, j = 0;
        int result = 0;
        while (i < haystack.size() && j < needle.size())
        {
            if (haystack[i] == needle[j])
            {
                // 之前while循环若判断result=-1，这里需要重新赋值一次
                if (result == -1)
                    result = i;
                i++;
                j++;
            }
            else
            {
                while (haystack[i] != needle[j] && j != 0)
                {
                    // 类似于构建next数组，若haystack和needle匹配过程中新的j不匹配，需要按j-1的最长公共前后缀
                    // 保留已匹配的长度，haystack保留右边，needle保留左边
                    j = next[j - 1];
                }
                if (haystack[i] == needle[j])
                {
                    // 这里重新赋值result，即needle与haystack匹配的新起点
                    // 保留已匹配的公共前后缀长度，haystack保留右边，needle保留左边
                    // 在比较的值是needle的下标j处相等，也就是一共j+1的长度已相等（如下标为3的总长度为4）
                    // 所以在比较的位置前面还有一段j长度的相同，要挪过去
                    result = i - j;
                    i++;
                    j++;
                }
                else
                {
                    // j退到0仍然不匹配，即表明目前没有公共前后缀，也没有任何匹配的值，只把i像右娜一些
                    result = -1;
                    i++;
                }
            }
        }
        // 返回解有可能包含和j前边匹配的i子串要剔除，两个串长度相减，刚好是最大可能result的下标
        //  haystack.size() -1 - [ needle.size()-1]
        return result > haystack.size() - needle.size() ? -1 : result;
    }
};