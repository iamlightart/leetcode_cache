// https://kamacoder.com/problempage.php?pid=1046
// #include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    // 初始化有几件物品，背包大小多少
    int gears_count, package_size; // gears_count package_size
    cin >> gears_count >> package_size;

    vector<int> gears_occupied(gears_count + 1), gears_value(gears_count + 1);
    // 初始化物品占用数组
    for (int i = 1; i <= gears_count; i++)
        cin >> gears_occupied[i]; // gears_occupied
    // 初始化物品价值数组
    for (int i = 1; i <= gears_count; i++)
        cin >> gears_value[i]; // gears_value
    // 初始化dp表，横向为背包大小递进，纵向为物品遍历，背包大小为0和物品占用为0均初始化为0
    vector<vector<int>> dp(package_size + 1, vector<int>(gears_count + 1, 0));
    // 不需要排序物品，因为最后的返回值会保证所有物品的尝试，无需注意先后顺序，是个组合问题而非排列
    // 外遍历物品，内递进背包增长，保证每一件物品都计算其依次填满背包的最大值
    for (int j = 1; j <= gears_count; j++)
    {
        for (int i = 1; i <= package_size; i++)
        {
            // 当前物品可能大于背包，先赋予可能每放入当前物品的值
            dp[i][j] = dp[i][j - 1];
            // 根据物品大小是否大于背包，决定放入物品的比较方式
            if (i >= gears_occupied[j])
            {
                // 当前最大值，为max(未放入当前物品最大值 ｜｜ 放入当前物品同时减去占用空间后，剩余空间在没放入当前物品时可能的最大值)
                dp[i][j] = max(dp[i][j - 1], dp[i - gears_occupied[j]][j - 1] + gears_value[j]);
            }
        }
    };
    // 返回dp表右下角值
    cout << dp[package_size][gears_count] << endl;
    return 0;
}