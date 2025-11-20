// https://kamacoder.com/problempage.php?pid=1065
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
// 完全反转，再按照需求长度翻转子串即可,这样不需要额外开辟空间
void reverseString(string &s, int start, int end)
{
    for (int i = start; i <= start + (end - start) / 2; i++)
    {
        char temp = s[i];
        s[i] = s[end - i + start];
        s[end - i + start] = temp;
    }
}
int main()
{
    int k = 0;
    string input_string;
    cin >> k;
    cin >> input_string;

    reverseString(input_string, 0, input_string.size() - 1);
    reverseString(input_string, 0, k - 1);
    reverseString(input_string, k, input_string.size() - 1);
    cout << input_string;
}

// 申请额外空间的方法,其实就是多了额外的子串空间，不是用一个字符处理的，效率差不多
int my_main()
{
    int k = 0;
    string input_string;
    cin >> k;
    cin >> input_string;

    string temp;
    for (int i = input_string.size() - k; i < input_string.size(); i++)
    {
        temp += input_string[i];
    };

    for (int i = input_string.size() - 1 - k; i >= 0; i--)
    {
        input_string[i + k] = input_string[i];
    }
    for (int i = 0; i < temp.size(); i++)
    {
        input_string[i] = temp[i];
    };
    cout << input_string << endl;
}