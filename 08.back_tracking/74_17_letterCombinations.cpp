// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        combImpl(digits, 0);
        return results;
    }

private:
    unordered_map<int, string> dialMap = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}};
    vector<string> results{};
    string temp_result{};
    void combImpl(string digits, int idx)
    {
        // 用ascii码的值连续性相减可以得到具体的值，两个char相减转换为int，如果直接转得到的是ascii值而非具体数
        string curr = dialMap[digits[idx] - '0'];
        for (int i = 0; i < curr.size(); i++)
        {
            // 结果长度与digit长度相等推入结果集，否则递归深入，不论如何该层最后都需要pop
            temp_result.push_back(curr[i]);
            if (temp_result.size() == digits.size())
                results.push_back(temp_result);
            if (temp_result.size() < digits.size())
                combImpl(digits, idx + 1);
            temp_result.pop_back();
        };
    }
};

int main()
{
    Solution s;
    vector<string> results = s.letterCombinations("23");
    for (auto c : results)
    {
        cout << c << endl;
    }
}