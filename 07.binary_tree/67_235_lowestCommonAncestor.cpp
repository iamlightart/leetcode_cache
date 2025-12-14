// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
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

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 若触底返回空指针，若遇到p或者q返回对应值
        if (!root || root == p || root == q)
            return root;
        // 其他条件下，走下面的分支
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        // 若p和q分别来自该node的左右分支，则该node为最小公共祖先，返回该node
        if (left && right)
            return root;
        // 若pq不来自左右分支，则只从一边来，那返回的值是相对浅的值
        else
        {
            return left ? left : right;
        }
    }
};