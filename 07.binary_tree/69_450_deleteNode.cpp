// https://leetcode.cn/problems/delete-node-in-a-bst/
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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        deleteImpl(root, key);
        return root;
    }

private:
    void deleteImpl(TreeNode *&node, int key)
    {
        if (!node)
            return;
        else if (node->val == key)
        {
            // 左或右为空时，直接删除节点，并把另一个分支接上
            if (node->right == nullptr)
                node = node->left;
            else if (node->left == nullptr)
                node = node->right;
            // 两个分支都不为空，默认取右边的值，把左边的分支接到最左边（bst的左分支最大值也一定小于右分支最小值）
            else
            {
                TreeNode *hodor = node;
                node = hodor->right;
                TreeNode *temp = node;
                while (temp->left)
                    temp = temp->left;
                temp->left = hodor->left;
                delete hodor;
            }
        }
        else
        {
            // 若为相等则按大小递归
            if (node->val > key)
                deleteImpl(node->left, key);
            if (node->val < key)
                deleteImpl(node->right, key);
        }
    }
};