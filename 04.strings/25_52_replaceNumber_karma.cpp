// https://kamacoder.com/problempage.php?pid=1064
//  2025-11-19
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
// 题的意思是让阔数组长度然后双指针处理
int main()
{
    string input_string;
    cin >> input_string;
    int count_num = 0;
    for (auto c : input_string)
    {
        if ((int)c >= 48 && (int)c <= 57)
            count_num++;
    }
    string result(static_cast<size_t>(count_num * 5 + input_string.size()), 'a');
    cout << result.size() << result << endl;
    int result_index = 0;
    char replace[6] = {'n', 'u', 'm', 'b', 'e', 'r'};
    while (result_index < result.size())
    {
        for (auto c : input_string)
        {
            if ((int)c >= 48 && (int)c <= 57)
            {
                // 如果for条件写错，所有替换操作都会失败，
                // for操作虽然时逐步而非原子性的，但还是可能返回空串
                for (size_t i = 0; i < 6; i++)
                {
                    result[result_index] = replace[i];
                    result_index++;
                }
            }
            else
            {
                result[result_index] = c;
                result_index++;
            }
        }
    }
    cout << result;
}
// 最傻解法
// int main()
// {
//     string input_string;
//     cin >> input_string;
//     vector<string> result{};
//     for (auto c : input_string)
//     {
//         if ((int)c >= 48 && (int)c <= 57)
//             cout << "number";
//         else
//             cout << c;
//     }
// }