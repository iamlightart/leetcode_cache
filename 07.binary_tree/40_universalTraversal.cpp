// https://leetcode.cn/problems/binary-tree-preorder-traversal/
// https://leetcode.cn/problems/binary-tree-postorder-traversal
// https://leetcode.cn/problems/binary-tree-inorder-traversal/description
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <unordered_set>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 数组中添加标记可以一次保持一致性的语法处理,前中后风格很统一
// 相当于提前给经过且确认了下层的值添加一个假的最底层null，这样下一次遇到这个值就直接弹出了
// 没有添加null的值就是没有确认下面是否有底部的值，需要重新确认，
// 第一次确认时添加伪null，第二次弹出

// 标记重补法？😂
class Solution
{
public:
    // 前序
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        if (root == nullptr)
            return result;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *temp = st.top();
            if (temp != nullptr)
            {
                st.pop();
                if (temp->right)
                    st.push(temp->right);
                if (temp->left)
                    st.push(temp->left);
                // 回栈的值后面添加一个null，这样如果下次再遇到就pop加入result了
                st.push(temp);
                st.push(nullptr);
            }
            else
            {
                st.pop();
                result.push_back(st.top()->val);
                st.pop();
            }
        }
        return result;
    }
    // 后序
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        if (root == nullptr)
            return result;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *temp = st.top();
            if (temp != nullptr)
            {
                st.pop();
                // 回栈的值后面添加一个null，这样如果下次再遇到就pop加入result了
                // 为了保持风格统一，其实可以直接push nullptr
                st.push(temp);
                st.push(nullptr);
                if (temp->right)
                    st.push(temp->right);
                if (temp->left)
                    st.push(temp->left);
            }
            else
            {
                st.pop();
                result.push_back(st.top()->val);
                st.pop();
            }
        }
        return result;
    }
    // 中序
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        if (root == nullptr)
            return result;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *temp = st.top();
            if (temp != nullptr)
            {
                st.pop();
                if (temp->right)
                    st.push(temp->right);
                // 回栈的值后面添加一个null，这样如果下次再遇到就pop加入result了
                st.push(temp);
                st.push(nullptr);
                if (temp->left)
                    st.push(temp->left);
            }
            else
            {
                st.pop();
                result.push_back(st.top()->val);
                st.pop();
            }
        }
        return result;
    }
};