// https://leetcode.cn/problems/n-queens/
#include <iostream>
using namespace std;
// 可以尝试将二维vector降低为一维数组，进一步降低复杂度
// 豆包和gpt给的解都是52.73%,可能是平台的问题了，证明算法复杂度应该没有错误
class StandardSolution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        // 初始化标记数组（核心优化：用3个一维数组替代二维棋盘）
        col_occupied.resize(n, false);           // 标记列是否被占用
        diag1_occupied.resize(2 * n - 1, false); // 正对角线（i-j + n-1）
        diag2_occupied.resize(2 * n - 1, false); // 反对角线（i+j）
        // 清空结果集（避免多次调用残留数据）
        results.clear();
        current_board.clear();

        // 从第0行开始回溯
        backtrack(n, 0);
        return results;
    }

private:
    // 冲突标记：仅记录列、正/反对角线是否被占用（O(n) 空间）
    vector<bool> col_occupied;
    vector<bool> diag1_occupied;
    vector<bool> diag2_occupied;
    vector<string> current_board;   // 当前构建的棋盘
    vector<vector<string>> results; // 所有合法解

    // 回溯核心函数：处理第 curr_row 行的皇后放置
    void backtrack(int n, int curr_row)
    {
        // 终止条件：所有行已放置皇后 → 收集解
        if (curr_row == n)
        {
            results.push_back(current_board);
            return;
        }

        // 遍历当前行的每一列，尝试放置皇后
        for (int col = 0; col < n; ++col)
        {
            // 计算对角线索引（避免负数，正对角线 i-j 范围：-(n-1)~n-1 → 偏移 n-1 转为 0~2n-2）
            int diag1 = curr_row - col + n - 1;
            int diag2 = curr_row + col;

            // 剪枝：当前列/对角线无冲突时才继续
            if (!col_occupied[col] && !diag1_occupied[diag1] && !diag2_occupied[diag2])
            {
                // 1. 放置皇后：标记冲突+构建当前行棋盘
                col_occupied[col] = true;
                diag1_occupied[diag1] = true;
                diag2_occupied[diag2] = true;
                current_board.emplace_back(n, '.'); // 构造全'.'的行
                current_board.back()[col] = 'Q';    // 当前列放皇后

                // 2. 递归处理下一行
                backtrack(n, curr_row + 1);

                // 3. 回溯：撤销皇后放置（恢复状态）
                current_board.pop_back();
                col_occupied[col] = false;
                diag1_occupied[diag1] = false;
                diag2_occupied[diag2] = false;
            }
        }
    }
};
//  将填入results的动作后的其他判断都过滤掉可以进一步提升，已经超过80%（有波动）
class OptmizeSolution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        occupied = vector<vector<int>>(n, vector<int>(n, 0));
        queenImpl(n, 0);
        return results;
    }

private:
    vector<vector<int>> occupied{};
    vector<string> result;
    vector<vector<string>> results;
    // 通过只在每行添加
    void queenImpl(int n, int curr_row)
    {
        if (curr_row > n)
            return;
        if (curr_row == n)
        {
            results.push_back(result);
            return;
        }
        for (int j = 0; j < n; j++)
        {
            if (occupied[curr_row][j] == 0)
            {
                modifyBoard(curr_row, j, n, 1);
                string temp = string(n, '.');
                temp[j] = 'Q';
                result.push_back(temp);
                queenImpl(n, curr_row + 1);
                modifyBoard(curr_row, j, n, -1);
                result.pop_back();
            }
        };
    }
    void modifyBoard(int row, int col, int size, int change)
    {
        occupied[row][col] += change;
        for (int i = row; i < size; i++)
        {
            occupied[i][col] += change;
            occupied[row][i] += change;

            for (int j = 0; j < size; j++)
            {
                if (i + j == row + col || i - j == row - col)
                {
                    occupied[i][j] += change;
                }
            }
        }
    }
};
// ❤️我做出来了，每行添加，降低了一层复杂度
class MySolution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        occupied = vector<vector<int>>(n, vector<int>(n, 0));
        queenImpl(n, 0);
        return results;
    }

private:
    vector<vector<int>> occupied{};
    vector<string> result;
    vector<vector<string>> results;
    // 通过只在每行添加需要的皇后，并只更新该行以下被占用的位置来优化效率
    // 击败50%
    void queenImpl(int n, int curr_row)
    {
        // 注意因为去掉了每一行都扫描的限制，需要额外加入返回限制，不然会导致buffer_overflow
        if (curr_row >= n)
            return;
        for (int j = 0; j < n; j++)
        {
            if (occupied[curr_row][j] == 0)
            {
                modifyBoard(curr_row, j, n, 1);
                string temp = string(n, '.');
                temp[j] = 'Q';
                result.push_back(temp);
                if (result.size() == n)
                    results.push_back(result);
                queenImpl(n, curr_row + 1);
                modifyBoard(curr_row, j, n, -1);
                result.pop_back();
            }
        };
    }
    void modifyBoard(int row, int col, int size, int change)
    {
        occupied[row][col] += change;
        for (int i = row; i < size; i++)
        {
            occupied[i][col] += change;
            occupied[row][i] += change;

            for (int j = 0; j < size; j++)
            {
                if (i + j == row + col || i - j == row - col)
                {
                    occupied[i][j] += change;
                }
            }
        }
    }
};
// 超时解，但代码逻辑应该是对的,每次都扫描全棋盘，复杂度超标
class SlowSolution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        occupied = vector<vector<int>>(n, vector<int>(n, 0));
        queenImpl(n, 0);
        return results;
    }

private:
    vector<vector<int>> occupied{};
    vector<string> result;
    vector<vector<string>> results;
    // 注意需要用curr_row控制行号需要对应，可能会把值填到其他行造成结果变多（比如[".Q..","...Q","..Q.","Q..."]这个明显的错误解就是行号乱了
    void queenImpl(int n, int curr_row)
    {
        for (int i = curr_row; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (occupied[i][j] == 0)
                {
                    modifyBoard(i, j, n, 1);
                    string temp = string(n, '.');
                    temp[j] = 'Q';
                    result.push_back(temp);
                    if (result.size() == n)
                        results.push_back(result);
                    queenImpl(n, curr_row + 1);
                    modifyBoard(i, j, n, -1);
                    result.pop_back();
                }
            };
        }
    }
    void modifyBoard(int row, int col, int size, int change)
    {
        occupied[row][col] += change;
        for (int i = 0; i < size; i++)
        {
            occupied[i][col] += change;
            occupied[row][i] += change;

            for (int j = 0; j < size; j++)
            {
                if (i + j == row + col || i - j == row - col)
                {
                    occupied[i][j] += change;
                }
            }
        }
    }
};