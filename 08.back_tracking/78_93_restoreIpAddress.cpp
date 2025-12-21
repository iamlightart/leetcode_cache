// https://leetcode.cn/problems/restore-ip-addresses/
#include <iostream>
using namespace std;
// 思路对了，效率只击败了50%
// 应该用 num = num * 10 + (s[i] - '0'); if (num > 255) break; 判断每一个三位数，效率更高
// 同时用 vector<int> 存结果，只在返回results处再做拼接
// 前导 0 剪枝 if (i > start && s[start] == '0') break; 确保023这样的值不进入结果集
class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        restoreImpl(s, 0);
        return results;
    }

private:
    vector<string> results{};
    vector<string> result{};
    void restoreImpl(string &s, int start)
    {
        // 进行大于4的剪枝提升效率
        if (result.size() > 4)
            return;
        // 这题和切字符串找回文的思路不一样，push_back的动作要在for循环外判断，
        //  for循环的条件不会在start==s.size()时进入
        if (result.size() == 4 && start == s.size())
            results.push_back(cast_result(result));
        for (int i = start; i < start + 3 && i < s.size(); i++)
        {

            // string to int;
            string temp = s.substr(start, i - start + 1);
            int num = stoi(temp);
            if (num >= 0 && num <= 255 && temp == to_string(num))
            {
                result.push_back(temp);
                restoreImpl(s, i + 1);
                // 注意pop_back的condition位置
                result.pop_back();
            }
        }
    };
    string cast_result(vector<string> &input)
    {
        string result = "";
        for (int i = 0; i < input.size(); i++)
        {
            result += input[i];
            if (i != input.size() - 1)
                result += ".";
        }
        return result;
    }
};
int main()
{
    Solution s;
    vector<string> result = s.restoreIpAddresses("25525511135");
    for (auto c : result)
    {
        cout << c << endl;
    }
}