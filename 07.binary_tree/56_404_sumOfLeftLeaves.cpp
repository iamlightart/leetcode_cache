// https://leetcode.cn/problems/sum-of-left-leaves/
#include <iostream>
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

public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
            return 0;
        else
        {
            int result = 0;
            calc_left(root, result);
            return result;
        }
    }

private:
    void calc_left(TreeNode *node, int &result)
    {
        if (node == nullptr)
            return;
        // 题干里面是左叶子之和 [1,2,3,4,5] 的结果是4而不是6
        if (node->left && node->left->left == nullptr && node->left->right == nullptr)
        {
            result += node->left->val;
        }
        if (node->left)
        {
            calc_left(node->left, result);
        }
        if (node->right)
        {
            calc_left(node->right, result);
        }
    }
};