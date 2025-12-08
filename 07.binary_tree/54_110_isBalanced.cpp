// https://leetcode.cn/problems/balanced-binary-tree/
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
// TODO ⚠️⚠️尝试用后序遍历完成判断，好像和dp还有点关系
// TODO ⚠️⚠️从这道题开始向后所有的题还没有尝试优化更好的算法！！！
class SlowSolution
{
public:
    bool isBalanced(TreeNode *root)
    {
    }

private:
    int calc_height(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        return 1 + max(calc_height(node->left), calc_height(node->right));
    }
};
// 这样可以每层判断，但没有记录每次计算的高度，所以效率低,应该用类似dp的方式来处理
class SlowSolution
{
public:
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        else if (root->left == nullptr && root->right == nullptr)
            return true;
        else
        {
            int left_hight = calc_height(root->left);
            int right_height = calc_height(root->right);
            // 在任何位置遇到高度不匹配直接return,不用递归到更深，效率提高
            if (abs(left_hight - right_height) > 1)
                return false;
            return isBalanced(root->left) && isBalanced(root->right) && (abs(left_hight - right_height) <= 1);
        }
    }

private:
    int calc_height(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        return 1 + max(calc_height(node->left), calc_height(node->right));
    }
};