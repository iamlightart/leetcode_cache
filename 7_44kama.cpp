#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int min_split(vector<int> &add_sum)
{
    int left = 0, right = 0;
    int result = INT32_MAX;
    for (size_t i = 0; i < add_sum.size() - 1; i++)
    {
        left = add_sum[i];
        right = add_sum[add_sum.size() - 1] - add_sum[i];
        result = min(result, abs(left - right));
    }
    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cin.ignore();                                 // cin按照单个变量读输入会留下一个换行符，需要清除掉
    vector<vector<int>> block(n, vector<int>(m)); // 矩阵本身没有用可以删掉
    vector<int> sum_row(n);
    vector<int> sum_col(m);
    vector<int> calc_row(n);
    vector<int> calc_col(m);
    for (size_t i = 0; i < n; i++)
    {
        string line;
        int temp = 0;
        getline(cin, line);
        istringstream iss(line); // 将字符串转为输入流
        for (size_t j = 0; j < m; j++)
        {
            iss >> temp;
            block[i][j] = temp; // 矩阵本身没有用可以删掉
            sum_row[i] += temp;
            sum_col[j] += temp;
        }
    }

    for (size_t i = 0; i < n; i++)
        calc_row[i] = i == 0 ? sum_row[i] : calc_row[i - 1] + sum_row[i];
    // 注意复制的时候不要把变量名改错了 calc_col[j] 被写成了 calc_row[j]导致提交异常
    for (size_t j = 0; j < m; j++)
        calc_col[j] = j == 0 ? sum_col[j] : calc_col[j - 1] + sum_col[j];

    int min_row = 0, min_col = 0;

    min_row = min_split(calc_row);
    min_col = min_split(calc_col);

    cout << min(min_row, min_col) << endl;
}

// 测试矩阵是否正确
//  for (auto col : block)
//  {
//      cout << "[";
//      for (auto num : col)
//      {
//          cout << num << ',';
//      }
//      cout << "]" << endl;
//  }