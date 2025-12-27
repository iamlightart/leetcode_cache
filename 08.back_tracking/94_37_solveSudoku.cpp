// https://leetcode.cn/problems/sudoku-solver/
#include <iostream>
using namespace std;
class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        // 1️⃣ 核心回溯逻辑已完成（AC），下一步优化目标：

        // 【效率优化 1】使用布尔数组缓存状态
        // - 当前每行/每列/每宫格已填数字用 bool 表示
        // - 优点：检查合法性 O(1)，替代每次遍历 9/9/9 个格子
        // 示例：
        // bool row[9][10], col[9][10], block[3][3][10];

        // 【效率优化 2】减少不必要的循环计算
        // - 当前每次 square_contains 都计算 row_start/col_start
        // - 优化：用固定公式或布尔数组代替，每次直接查表

        // 【搜索顺序优化 3】最小剩余值（MRV）
        // - 先填候选数字最少的空格，减少回溯分支
        // - 可维护空格列表或在 DFS 前计算每个空格可填数字数量

        // 【搜索顺序优化 4】按约束强度选择数字顺序
        // - 可以优先尝试频率低或限制多的数字，减少 DFS 深度

        // 【代码清理 5】去掉无效的 row_start/col_start 判断
        // - 当前写法 i<row_start && j<col_start continue 没有意义，可删

        // 【小技巧 6】DFS 返回值布尔用法已正确
        // - 保持 return true/false 控制搜索
        // - 进一步可以在 top-level 调用前统计空格列表，提高访问顺序可控

        // 【可选】进一步优化 7：位运算（高级）
        // - 使用位掩码记录行/列/宫格数字出现状态
        // - 可进一步加速合法性检查，减少常数操作
    }
};
// gpt说和答案复杂度一样，但比较慢的解，有几个需要优化的地方
class SlowSolution
{
private:
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        // 用bool来判断return，可合理中止局部流程
        solveImpl(board, 0, 0);
    }
    bool solveImpl(vector<vector<char>> &board, int row_start, int col_start)
    {

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                // 该逻辑没有减少访问节点数
                //  if (i < row_start && j < col_start)
                //      continue;
                if (board[i][j] == '.')
                {
                    for (int k = 1; k <= 9; k++)
                    {
                        if (!row_contains(board, i, k) && !col_contains(board, j, k) && !square_contains(board, i, j, k))
                        {
                            board[i][j] = k + '0';
                            // ⚠️⚠️⚠️当下层正确完成了填空return true,上层也会return true
                            // 用bool的方式可以巧妙的处理结果集不另外存在的情况
                            if (solveImpl(board, i, j))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    // 若有值改回了‘.’，证明此位置的数填错了，直接终端该层算法 return false
                    return false;
                }
            }
        }
        // 扫描棋盘没有任何空格，或者没进入上两层for，就返回true
        return true;
    }
    bool row_contains(vector<vector<char>> &board, int row, int val)
    {
        for (int i = 0; i < board.size(); i++)
        {
            if (board[row][i] - '0' == val)
                return true;
        }
        return false;
    }
    bool col_contains(vector<vector<char>> &board, int col, int val)
    {
        for (int j = 0; j < board.size(); j++)
        {
            if (board[j][col] - '0' == val)
                return true;
        }
        return false;
    }
    bool square_contains(vector<vector<char>> &board, int row, int col, int val)
    {
        // int row_start = row - 1 < 0 ? 0 : row - 1;
        // int row_end = row + 1 > board.size() - 1 ? board.size() - 1 : row + 1;
        // int col_start = col - 1 < 0 ? 0 : col - 1;
        // int col_end = col + 1 > board.size() - 1 ? board.size() - 1 : col + 1;

        // ⚠️ 注意正确计算该节点所被包含的九宫格，不是这个节点周围的八个点，上面的初始化方式是错的
        int row_start = row / 3 * 3;
        int row_end = row_start + 2;
        int col_start = col / 3 * 3;
        int col_end = col_start + 2;

        for (int i = row_start; i <= row_end; i++)
        {
            for (int j = col_start; j <= col_end; j++)
            {
                if (board[i][j] - '0' == val)
                    return true;
            }
        }
        return false;
    }
};