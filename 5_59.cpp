#include <iostream>
#include <vector>
using namespace std;
// https://leetcode.cn/problems/spiral-matrix-ii/description/
//  2025-11-11

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        // vector需要初始化分配内存，不然会报空指针
        vector<vector<int>> result(n, vector<int>(n));
        fill_loop(result, 0, 0, n, 1, n * n);
        return result;
    }

    void fill_loop(vector<vector<int>> &result, int start_x, int start_y, int border_length, int current_val, int max_val)
    {
        // 当前值大于最大值，返回
        if (current_val > max_val)
            return;
        // 当边长为1，填入返回
        if (border_length == 1)
        {
            if (border_length == 1)
            {
                result[start_x][start_y] = current_val;
                return;
            }
        }
        for (int i = 0; i < border_length - 1; i++)
        {
            result[start_x][start_y + i] = current_val++;
        }
        for (int i = 0; i < border_length - 1; i++)
        {
            result[start_x + i][start_y + border_length - 1] = current_val++;
        }
        for (int i = border_length - 1; i >= 1; i--)
        {
            result[start_x + border_length - 1][start_y + i] = current_val++;
        }
        for (int i = border_length - 1; i >= 1; i--)
        {
            result[start_x + i][start_y] = current_val++;
        }
        // 下一层的边长首尾各去掉1，一共是减2
        fill_loop(result, start_x + 1, start_y + 1, border_length - 2, current_val, max_val);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> result = s.generateMatrix(3);
    for (auto vec : result)
    {
        cout << "[";
        for (auto num : vec)
        {
            cout << num << ", ";
        }
        cout << "], ";
    }
}