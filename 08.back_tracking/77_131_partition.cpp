// https://leetcode.cn/problems/palindrome-partitioning/
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        partitionImpl(s, 0);
        return results;
    }
    vector<vector<string>> results;
    vector<string> result;
    // string hodor = "";
    // string hodor_prev = "";
    void partitionImpl(string &s, int start)
    {
        for (int i = start; i < s.size(); i++)
        {
            string temp = s.substr(start, i - start + 1);
            if (isPalindrome(temp))
            {
                result.push_back(temp);
                // hodor_prev = hodor;
                // hodor += temp;
                if (i == s.size() - 1)
                    results.push_back(result);
                else
                    partitionImpl(s, i + 1);
                result.pop_back();
                // hodor = hodor_prev;
            }
        }
    }
    // 用左右指针效率更高
    bool isPalindrome(string &s)
    {
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            if (s[left] != s[right])
                return false;
            else
            {
                left++;
                right--;
            }
        }
        return true;
    }
    // 反转判断回文数效率略低，但提交没有显示
    // bool isPalindrome(string &s)
    // {
    //     string temp = s;
    //     reverse(temp.begin(), temp.end());
    //     return (temp == s) ? true : false;
    // }
};