#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 性能有问题，值传递result会造成大量拷贝，用引用传递和回溯处理比较好。今天头不舒服明天再弄了
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> path_p = get_path(root, p);
        vector<TreeNode *> path_q = get_path(root, q);
        TreeNode *result{};
        int length = min(path_p.size(), path_q.size());
        if (length == 1)
            return path_p[0];
        for (int i = 0; i < length - 1; i++)
        {
            if (path_p[i] != path_q[i])
                return path_p[i - 1];
        }
        return path_p.size() > path_q.size() ? path_q[length - 1] : path_p[length - 1];
    }

private:
    vector<TreeNode *> tempResult;
    vector<TreeNode *> get_path(TreeNode *root, TreeNode *end)
    {
        vector<TreeNode *> result{};
        if (root == nullptr)
            return result;
        get_path_impl(root, end, result);
        result = tempResult;
        tempResult.clear();
        return result;
    };
    bool get_path_impl(TreeNode *node, TreeNode *target, vector<TreeNode *> result)
    {
        if (!node)
            return false;
        result.push_back(node);
        if (node == target)
        {
            tempResult = result;
            return true;
        }

        else
        {
            if (get_path_impl(node->left, target, result))
                return true;
            if (get_path_impl(node->right, target, result))
                return true;
        }
        return false;
    };
};