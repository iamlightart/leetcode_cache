// https://leetcode.cn/problems/path-sum/description/
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
// 不论小大都触底， 100%
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;
        else
            return hasPathSumImpl(root, targetSum, 0);
    }
    bool hasPathSumImpl(TreeNode *node, int targetSum, int currSum)
    {

        if (node == nullptr)
            return false;
        currSum += node->val;
        // 除了这一种情况为true,其他不论currSum和targetSum的比较值是多少都要触底验证
        // 因为其他的因为路径上可能存在负数，无法在触底之前就判断是否可以得到正确的值
        if (currSum == targetSum && node->left == nullptr && node->right == nullptr)
            return true;
        else
            return hasPathSumImpl(node->left, targetSum, currSum) || hasPathSumImpl(node->right, targetSum, currSum);
        return false;
    }
};