#include <iostream>
using namespace std;
// gpt将push的动作从for中提了出来，理论上能更快一点
class gptSolution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> num_array{};
        for (int i = 1; i <= n; i++)
        {
            num_array.push_back(i);
        }
        vector<int> temp_result{};
        combineImpl(num_array, temp_result, k, 0);
        return results;
    }

private:
    vector<vector<int>> results;
    void combineImpl(vector<int> &num_array, vector<int> &temp_result, int left_count, int start)
    {
        if (left_count == 0)
        {
            results.push_back(temp_result);
            return;
        }

        // 注意是nums_array.size()-left_count,不是left_count本身
        for (int i = start; i <= num_array.size() - left_count; i++)
        {
            temp_result.push_back(num_array[i]);
            combineImpl(num_array, temp_result, left_count - 1, i + 1);
            temp_result.pop_back();
        }
    }
};
// 除了边界值和i++的特性不熟，几乎一次通过
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> num_array{};
        for (int i = 1; i <= n; i++)
        {
            num_array.push_back(i);
        }
        vector<int> temp_result{};
        combineImpl(num_array, temp_result, k, 0);
        return results;
    }

private:
    vector<vector<int>> results;
    void combineImpl(vector<int> &num_array, vector<int> &temp_result, int left_count, int start)
    {
        // 注意是nums_array.size()-left_count,不是left_count本身
        for (int i = start; i <= num_array.size() - left_count; i++)
        {
            temp_result.push_back(num_array[i]);
            if (left_count == 1)
                results.push_back(temp_result);
            else
                // ⚠️参数如此传入子函数left_count--,i++,会改变当前父函数内的left_count和i++，导致递归状态异常
                // 递归过程中使用无副作用的 left_count - 1, i + 1！
                //  combineImpl(num_array, temp_result, left_count--, i++);
                combineImpl(num_array, temp_result, left_count - 1, i + 1);
            temp_result.pop_back();
        }
    }
};

int main()
{
    Solution s;
    s.combine(4, 2);
}