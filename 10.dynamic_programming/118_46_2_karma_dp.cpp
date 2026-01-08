// #include <bits/stdc++.h> 是 GCC / Clang 提供的“万能头文件合集”
#include <iostream>
using namespace std;
// gpt标准解
int main()
{
    int gears_count, package_size; // gears_count package_size
    cin >> gears_count >> package_size;

    vector<int> gears_occupied(gears_count + 1), gears_value(gears_count + 1);
    for (int i = 1; i <= gears_count; i++)
        cin >> gears_occupied[i]; // gears_occupied
    for (int i = 1; i <= gears_count; i++)
        cin >> gears_value[i]; // gears_value

    vector<vector<int>> dp(package_size + 1, vector<int>(gears_count + 1, 0));

    for (int j = 1; j <= gears_count; j++)
    {
        for (int i = 0; i <= package_size; i++)
        {
            dp[i][j] = dp[i][j - 1]; // 不选
            if (i >= gears_occupied[j])
            {
                dp[i][j] = max(
                    dp[i][j],
                    dp[i - gears_occupied[j]][j - 1] + gears_value[j]);
            }
        }
    }

    cout << dp[package_size][gears_count] << endl;
    return 0;
}
// 干净版本
// #include <bits/stdc++.h>
using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;

    vector<int> w(M + 1), v(M + 1);
    for (int i = 1; i <= M; i++)
        cin >> w[i];
    for (int i = 1; i <= M; i++)
        cin >> v[i];

    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

    for (int j = 1; j <= M; j++)
    {
        for (int i = 0; i <= N; i++)
        {
            dp[i][j] = dp[i][j - 1]; // 不选
            if (i >= w[j])
            {
                dp[i][j] = max(
                    dp[i][j],
                    dp[i - w[j]][j - 1] + v[j]);
            }
        }
    }

    cout << dp[N][M] << endl;
    return 0;
}
