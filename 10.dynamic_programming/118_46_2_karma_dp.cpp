// #include <bits/stdc++.h> 是 GCC / Clang 提供的“万能头文件合集”
#include <iostream>
using namespace std;
// gpt标准解
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
