// https://leetcode.cn/problems/validate-binary-search-tree/
// Definition for a binary tree node.
#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 中序解法，不如前序思路直观，但是更简洁
class Solution
{
public:
    long long prev = LLONG_MIN;
    bool isValidBST(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        if (!isValidBST(root->left))
            return false;
        if (root->val <= prev)
            return false;
        prev = root->val;
        // 每次返回的root->right,是上一层isValidBST(root->left)的返回值
        return isValidBST(root->right);
    }
};
// 中序标准答案，对中序遍历不太熟悉，用的少
// 中序就是本层的right返回值，上一层的left返回值
class inorderAnswer
{
public:
    long long prev = LLONG_MIN;
    bool isValidBST(TreeNode *root)
    {
        // 指针可以用作bool判断nullptr即false,其他均为true
        // 指针类型在布尔上下文中，会被隐式转换为 bool
        // 空指针转换为 false
        // 非空指针转换为 true
        if (!root)
            return true;
        if (!isValidBST(root->left))
            return false;
        if (root->val <= prev)
            return false;
        prev = root->val;
        return isValidBST(root->right);
    }
};

// 需要考虑边界值的情况，按照答案看中序最简单，不用考虑bound的情况
class EdgeDesignSolution
{
public:
    bool isValidBST(TreeNode *root)
    {
        // 需要用longlong来处理边界，其实并不好，如果取之范围也到了LLONG_MIN/MAX呢？
        return isValidBSTImpl(root, LLONG_MIN, LLONG_MAX);
    }

private:
    bool isValidBSTImpl(TreeNode *node, long long min_bound, long long max_bound)
    {

        if (node == nullptr)
            return true;
        if (node->left == nullptr && node->right == nullptr)
            return true;
        if (node->left)
        {
            if (node->left->val >= node->val || node->left->val <= min_bound)
                return false;
        }
        if (node->right)
        {
            if (node->right->val <= node->val || node->right->val >= max_bound)
                return false;
        }
        return isValidBSTImpl(node->left, min_bound, node->val) && isValidBSTImpl(node->right, node->val, max_bound);
    };
};

// 重复遍历了太多情况，效率低
class SlowSolution
{
public:
    bool isValidBST(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        else if (root->left == nullptr && root->right == nullptr)
            return true;
        else
        {

            if (root->left)
            {
                TreeNode *temp = root->left;
                while (temp != nullptr)
                {
                    if (temp->val >= root->val)
                        return false;
                    temp = temp->right;
                }
            }

            if (root->right)
            {
                TreeNode *temp = root->right;
                while (temp != nullptr)
                {
                    if (temp->val <= root->val)
                        return false;
                    temp = temp->left;
                }
            }
        }
        return isValidBST(root->left) && isValidBST(root->right);
    }
};