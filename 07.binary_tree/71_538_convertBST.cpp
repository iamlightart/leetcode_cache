// https://leetcode.cn/problems/convert-bst-to-greater-tree/
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
// gpt给出了更优雅的解，反向中序可以从最大值入手，不用存中间状态，直接加到哪里存到哪里
class gptSolution
{
public:
    int sum = 0;
    TreeNode *convertBST(TreeNode *root)
    {
        if (root)
            dfs(root);
        return root;
    }

    void dfs(TreeNode *node)
    {
        if (node->right)
            dfs(node->right);
        sum += node->val;
        node->val = sum;
        if (node->left)
            dfs(node->left);
    }
};
// 正向中序先存sum值，再挨个改值
class Solution
{
    vector<int> sum_hodor{};

public:
    TreeNode *convertBST(TreeNode *root)
    {
        if (root)
        {
            get_sum(root);
            change_val(root);
        }
        return root;
    }

private:
    int curr_sum = 0;
    int index = -1;
    void get_sum(TreeNode *node)
    {
        if (node->left)
            get_sum(node->left);
        curr_sum += node->val;
        sum_hodor.push_back(curr_sum);
        if (node->right)
            get_sum(node->right);
    }
    void change_val(TreeNode *node)
    {
        if (node->left)
            change_val(node->left);
        // 因为是大于或等于该node的值，第一个node不需要减去任何值，第n个node减去前n-1个node的sum
        node->val = index == -1 ? curr_sum : curr_sum - sum_hodor[index];
        index++;
        if (node->right)
            change_val(node->right);
    }
};