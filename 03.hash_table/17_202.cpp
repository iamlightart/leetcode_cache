// https://leetcode.cn/problems/happy-number/description/
// 2025年11月16日
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> pass_num;
        int curr = n;
        //  下面的错误在于快乐数的循环开始点不一定是n!
        // int loop_start = n;
        //  do{...}while (curr != loop_start);
        while (pass_num.find(curr) == pass_num.end())
        {
            pass_num.insert(curr);
            int temp = curr;
            curr = 0;
            while (temp)
            {
                // curr += temp % 10 * temp % 10写法错误，%和*的判定会出现问题;
                curr += (temp % 10) * (temp % 10);
                // 这里应该/=10 才能正确的减小temp
                temp /= 10;
            }
            if (curr == 1)
                return true;
        }

        return false;
    }
};

int main()
{
    Solution s;
    cout << boolalpha << s.isHappy(19) << endl;
}
