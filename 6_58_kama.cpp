#include <iostream>
#include <vector>
using namespace std;
// https://kamacoder.com/problempage.php?pid=1070
// 2025-11-12
int main()
{
    int line_num;
    cin >> line_num;
    vector<int> input_array(line_num);
    vector<int> input_sum(line_num);
    for (size_t i = 0; i < line_num; i++)
    {
        int temp;
        std::cin >> temp;
        input_array[i] = temp;
        input_sum[i] = i == 0 ? temp : input_sum[i - 1] + temp;
    }
    int start, end;
    // 直接计算会超时，因为会重复计算，用一个结果和的集input_sum来处理比较好
    // while (cin >> start >> end)
    // {
    //     int result = 0;
    //     for (int i = start; i <= end; i++)
    //     {
    //         result += input_array[i];
    //     };

    //     cout << result << endl;
    // }
    while (cin >> start >> end)
    {
        int result = start == 0 ? input_sum[end] : input_sum[end] - input_sum[start - 1];
        cout << result << endl;
    }
}