
// https://leetcode.cn/problems/find-mode-in-binary-search-tree/
#include <iostream>
#include <map>
using namespace std;
//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
    bool first_node = true;

    int max_count = 0;
    int curr_count = 0;
    int curr_val{};
    vector<int> result{};

public:
    vector<int> findMode(TreeNode *root)
    {
        if (root == nullptr)
            return result;
        getResult(root);
        if (curr_count >= max_count)
        {
            if (curr_count > max_count)
            {
                result.clear();
                // cout << "maxcount:" << max_count << "currcount" << curr_count << endl;
                // cout << "clear result" << endl;
            }

            result.push_back(curr_val);
            // cout << "push_back:" << curr_val << endl;
        }
        return result;
    }

    void getResult(TreeNode *node)
    {
        if (node->left)
            getResult(node->left);
        if (first_node)
        {
            curr_val = node->val;
            curr_count = 1;
            // 哈哈哈哈😂，没有在初始化firstnode的时候更新max_count,卡了两个小时
            max_count = 1;
            first_node = false;
        }
        else
        {
            if (node->val == curr_val)
            {
                curr_count++;
                if (curr_count > max_count)
                {
                    max_count = curr_count;
                    result.clear();
                    // cout << "clear result" << endl;
                }
            }
            else
            {
                if (curr_count == max_count)
                    // 注意push的值是curr_val不是node->val
                    result.push_back(curr_val);
                // cout << "push_back:" << curr_val << endl;
                curr_count = 1;
                curr_val = node->val;
            }
        }
        if (node->right)
            getResult(node->right);
    }
};
int main()
{
    TreeNode *n = new TreeNode(1, nullptr, new TreeNode(2));
    Solution s;
    s.findMode(n);
}
// bst的中序搜索天然排序，不需要再遍历一次，效率会更高
// 通过了但是复杂，且gpt一直说有错，还是改个语义更精炼的版本
class ComplexStateSolution
{
    int current{};
    int curr_count{};
    int max_count = INT_MIN;
    bool firstNode = true;
    vector<int> result{};

public:
    vector<int> findMode(TreeNode *root)
    {
        if (root == nullptr)
            return result;
        get_result(root);
        if (curr_count < max_count)
            result.pop_back();
        return result;
    }
    void get_result(TreeNode *root)
    {
        // 左
        if (root->left)
            get_result(root->left);
        // 中
        if (firstNode)
        {
            result.push_back(root->val);
            current = root->val;
            curr_count = 1;
            firstNode = false;
        }
        else
        {
            if (root->val != current)
            {
                if (curr_count < max_count)
                    result.pop_back();
                result.push_back(root->val);
                current = root->val;
                curr_count = 1;
            }
            else
            {
                curr_count++;
                if (curr_count > max_count)
                {
                    max_count = curr_count;
                    result.clear();
                    result.push_back(current);
                }
            }
        }
        // 右
        if (root->right)
            get_result(root->right);
    }
};
// 前序效率低，考虑用中序
class SlowSolution
{
    unordered_map<int, int> hodor{};
    vector<int> result{};

public:
    vector<int> findMode(TreeNode *root)
    {
        if (root == nullptr)
            return result;
        fill_hodor(root);
        int max_calc = INT_MIN;
        for (auto pair : hodor)
        {
            if (pair.second > max_calc)
            {
                max_calc = pair.second;
                result.clear();
                result.push_back(pair.first);
            }
            else if (pair.second == max_calc)
            {
                result.push_back(pair.first);
            }
        }
        return result;
    }

private:
    void fill_hodor(TreeNode *root)
    {
        // 直接++即可，不存在的key会自动构建一个<int,int> second默认值为0
        hodor[root->val]++;
        if (root->left)
            fill_hodor(root->left);
        if (root->right)
            fill_hodor(root->right);
    };
};