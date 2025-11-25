// https://leetcode.cn/problems/repeated-substring-pattern/
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

class Solution
{
public:
    // 右值传引用，需要const
    // 右值传引用，需要const
    vector<int> form_next(const string &s)
    {
        vector<int> result((int)s.size(), 0);

        if (s.size() == 1)
            return result;
        else
        {
            int i = 0, j = 1;
            while (j < s.size())
            {
                if (s[i] == s[j])
                {
                    result[j] = result[j - 1] + 1;
                    i++;
                    j++;
                }

                else
                {
                    while (i != 0 && s[i] != s[j])
                    {
                        i = result[i - 1];
                        if (i == 0)
                            break;
                    }

                    if (s[i] == s[j])
                    {
                        result[j] = i + 1;
                        i++;
                        j++;
                    }
                    else
                    {
                        result[j] = 0;
                        j++;
                    }
                }
            };
        }
        return result;
    };

    bool repeatedSubstringPattern(string s)
    {
        vector<int> next = form_next(s);
        if (next[s.size() - 1] == 0)
            return false;
        string pattern = s.substr(0, s.size() - next[s.size() - 1]);
        if (s.size() % pattern.size() != 0)
            return false;
        // 只要余数为0即为结果，不需要截取子串验证
        // 数学证明 file://./imgs/29_459.jpg
        // else
        // {
        //     for (int i = pattern.size(); i < s.size(); i += pattern.size())
        //     {
        //         string temp = s.substr(i, pattern.size());
        //         if (temp != pattern)
        //             return false;
        //     }
        // }
        return true;
    }
};
template <typename t>
void print_vector(vector<t> next)
{
    cout << "[";
    for (auto c : next)
    {
        cout << c << ",";
    }
    cout << "]" << endl;
}

int main()
{
    // ababababababaababababababaababababababa
    Solution s;
    vector<int> next = s.form_next("abab");
    print_vector(next);
    // next = s.buildNext("abab");
    // print_vector(next);
    cout << boolalpha << s.repeatedSubstringPattern("abab") << endl;
};