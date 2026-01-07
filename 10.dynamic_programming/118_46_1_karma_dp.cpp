// https://kamacoder.com/problempage.php?pid=1046
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm> // 新增：sort 必需的头文件
#include <cmath>     // 替换 math.h（C++ 推荐用 cmath）
using namespace std;
void format_vector(vector<int> &hodor)
{
    int num;
    while (cin >> num)
    {
        hodor.push_back(num);
        if (cin.peek() == '\n')
            break;
    }
}
// ❌ 不用排序物品，边界有错
int main()
{
    int count;
    int package_size;
    // 物品占用
    vector<int> occupied;
    // 物品价值
    vector<int> value;
    cin >> count >> package_size;
    format_vector(occupied);
    format_vector(value);
    // 存放所有物品占用和价值
    vector<vector<int>> gears(count);
    for (int i = 0; i < gears.size(); i++)
        gears[i] = {occupied[i], value[i]};
    sort(gears.begin(), gears.end(), [](const vector<int> &a, vector<int> &b)
         {if(a[0]!=b[0])
            return a[0]<b[0]; 
            else    
            return a[1]<b[1]; });

    if (gears[0][0] > package_size)
        return 0;

    vector<vector<int>> hodor(package_size);

    for (int i = 0; i < hodor.size(); i++)
    {
        vector<int> temp(gears.size());
        hodor[i] = temp;
    }

    for (int i = 0; i < package_size; i++)
    {
        for (int j = 0; j < gears.size(); j++)
        {
            if (j == 0)
            {
                hodor[i][j] = gears[0][1];
            }
            else
            {
                hodor[i][j] = max(hodor[i][j - 1], hodor[i - gears[j][0]][j] + gears[j][1]);
            }
        };
    }
    return hodor[package_size - 1][gears.size() - 1];
}