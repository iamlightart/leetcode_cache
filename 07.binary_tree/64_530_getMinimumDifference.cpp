// https://leetcode.cn/problems/minimum-absolute-difference-in-bst/
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
// 直觉inorder做法为了保证prev的值一直正确，必须排除第一次计算
// 因为inorder处理的第一个节点一定是第一次计算要用到的，用一个flag标记即可
class Solution
{
    int result = INT_MAX;
    int prev = INT_MAX;
    bool firstNode = true;

public:
    int getMinimumDifference(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        getMinimumDifference(root->left);
        // 用第一次判断来排除第一个node的第一次计算
        if (!firstNode)
            result = min(result, abs(root->val - prev));
        else
            firstNode = false;
        prev = root->val;
        getMinimumDifference(root->right);
        return result;
    }
};

// 哦！💡 因为是二叉搜索树，天然存在排序，用中序来处理
class inorderSolution
{
    int result = INT_MAX;
    int prev = INT_MAX;

public:
    int getMinimumDifference(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        getMinimumDifference(root->left);
        result = min(result, abs(root->val - prev));
        prev = root->val;
        getMinimumDifference(root->right);
        return result;
    }
};
//  直接想出来的感觉相当于暴力解，效率不高
class Solution
{
    vector<int> hodor{};
    int result = INT_MAX;

public:
    int getMinimumDifference(TreeNode *root)
    {
        if (!root)
            return 0;
        collect_nums(root);
        sort(hodor.begin(), hodor.end());
        for (int i = 0; i < hodor.size() - 1; i++)
        {
            int temp = abs(hodor[i] - hodor[i + 1]);
            if (temp < result)
                result = temp;
        }
        return result;
    }
    void collect_nums(TreeNode *root)
    {
        hodor.push_back(root->val);
        if (root->left)
            collect_nums(root->left);
        if (root->right)
            collect_nums(root->right);
    }
};
// 注意看是两个值之间的最小值，而不是两个最小值之间的值😂
class WrongSolution
{
    int first_min = INT_MAX, second_min = INT_MAX;

public:
    int getMinimumDifference(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        get_first(root);
        get_second(root);
        return abs(first_min - second_min);
    }

private:
    void get_first(TreeNode *root)
    {
        if (root->val < first_min)
        {
            first_min = root->val;
        }
        if (root->left)
            get_first(root->left);
        if (root->right)
            get_first(root->right);
    }
    void get_second(TreeNode *root)
    {
        if (root->val < second_min && root->val > first_min)
        {
            second_min = root->val;
        }
        if (root->left)
            get_second(root->left);
        if (root->right)
            get_second(root->right);
    }
};