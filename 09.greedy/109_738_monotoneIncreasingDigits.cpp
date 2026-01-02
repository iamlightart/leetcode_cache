// https://leetcode.cn/problems/monotone-increasing-digits/description/
#include <string>
#include <iostream>
using namespace std;
class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {
        // int转为string
        string s = to_string(n);
        for (int i = s.size() - 2; i >= 0; i--)
        {
            if (s[i] - '0' > s[i + 1] - '0')
            {
                s[i] = s[i] - '0' - 1 + '0';
                for (int j = i + 1; j < s.size(); j++)
                    s[j] = '9';
            }
        };
        // string转为int
        return stoi(s);
    }
};

int main()
{
    Solution s;
    cout << s.monotoneIncreasingDigits(332) << endl;
}