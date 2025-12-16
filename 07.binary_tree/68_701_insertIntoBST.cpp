// https://leetcode.cn/problems/insert-into-a-binary-search-tree/
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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (!root)
            root = new TreeNode(val);
        else
            insertImpl(root, val);
        return root;
    }

private:
    // 直接用指针做参数也是值传递，想用同一个指针必须要加引用
    void insertImpl(TreeNode *&root, int val)
    {
        if (!root)
            root = new TreeNode(val);
        else
        {
            if (root->val > val)
                insertImpl(root->left, val);
            if (root->val < val)
                insertImpl(root->right, val);
        }
    }
};