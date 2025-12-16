
// https://leetcode.cn/problems/trim-a-binary-search-tree/
#include <iostream>
using namespace std;
// Definition for a binary tree node.
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
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (root)
            trimImpl(root, low, high);
        return root;
    }

private:
    void trimImpl(TreeNode *&node, int low, int high)
    {
        if (!node)
            return;

        while (node->val < low || node->val > high)
        {
            node = node->val < low ? node->right : node->left;
            if (!node)
                return;
        }

        if (node->left && node->left->val < low)
            node->left = node->left->right;
        if (node->right && node->right->val > high)
            node->right = node->right->left;

        if (node->left)
            trimImpl(node->left, low, high);
        if (node->right)
            trimImpl(node->right, low, high);
    }
};