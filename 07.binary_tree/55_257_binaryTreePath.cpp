// https://leetcode.cn/problems/binary-tree-paths/description/
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
class solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> results{};
        if (root == nullptr)
            return results;
        // "" 的类型是 const char[1]（空字符串字面量，底层是指向只读内存的 const char* 指针，指向一个 '\0' 字符）；
        // C++ 中，指针 + 整数 = 「指针偏移」（不是字符串拼接）
        // string s = "" + root->val;
        string s = to_string(root->val);
        if (root->left == nullptr && root->right == nullptr)
        {
            results.push_back(s);
            return results;
        }
        if (root->left)
            get_all_path(root->left, results, s);
        if (root->right)
            get_all_path(root->right, results, s);
        return results;
    }

private:
    void get_all_path(TreeNode *node, vector<string> &results, string cur_res)
    {
        // if (node == nullptr)
        //     return;
        // 这里也要用to_string
        cur_res = cur_res + "->" + to_string(node->val);
        if (node->left == nullptr && node->right == nullptr)
            results.push_back(cur_res);
        else
        {
            if (node->left)
                get_all_path(node->left, results, cur_res);
            if (node->right)
                get_all_path(node->right, results, cur_res);
        }
    };
};

// TODO string 按值传递效率低，考虑按引用传递，如何做增删
class string_path_by_val_solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> results{};
        if (root == nullptr)
            return results;
        // "" 的类型是 const char[1]（空字符串字面量，底层是指向只读内存的 const char* 指针，指向一个 '\0' 字符）；
        // C++ 中，指针 + 整数 = 「指针偏移」（不是字符串拼接）
        // string s = "" + root->val;
        string s = to_string(root->val);
        if (root->left == nullptr && root->right == nullptr)
        {
            results.push_back(s);
            return results;
        }
        if (root->left)
            get_all_path(root->left, results, s);
        if (root->right)
            get_all_path(root->right, results, s);
        return results;
    }

private:
    void get_all_path(TreeNode *node, vector<string> &results, string cur_res)
    {
        // if (node == nullptr)
        //     return;
        // 这里也要用to_string
        cur_res = cur_res + "->" + to_string(node->val);
        if (node->left == nullptr && node->right == nullptr)
            results.push_back(cur_res);
        else
        {
            if (node->left)
                get_all_path(node->left, results, cur_res);
            if (node->right)
                get_all_path(node->right, results, cur_res);
        }
    };
};