// https://leetcode.cn/problems/binary-tree-inorder-traversal/description/
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
// 中序就是在中间
// 遍历方法，每次节点被pop()后再将这个节点的right节点入栈
// 每次都是左边彻底空了就往右边执行
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> tempStack;
        inOrder(root, result, tempStack);
        return result;
    }
    void inOrder(TreeNode *node, vector<int> &result, stack<TreeNode *> &tempStack)
    {
        if (node == nullptr)
            return;
        else
        {
            TreeNode *temp = node;
            // temp != nullptr 用来判断指针当前位置，若不为空则下面还有可能有左子树的值要更先输出
            //  !tempStack.empty() 只要栈不空就要继续执行，这时候temp可以=nullptr
            while (temp != nullptr || !tempStack.empty())
            {
                // temp不为空，则入栈，向左走
                if (temp != nullptr)
                {
                    // 每一个入栈的值，都是下一层的中序值
                    tempStack.push(temp);
                    temp = temp->left;
                }
                // 当前temp==null证明二叉树触底，将temp指向top并将值加入result：
                // 1.   指向left的null而触底，证明上一层的中序值没有左子树需要先输出了。
                //      temp重新指向的top是上一层的中序值，加入result，temp指向right，因为中序值输出后该输出右子树
                //
                // 2.   指向right的null而触底，证明到上一层的这棵子树遍历完了。
                //      temp重新指向的top是这颗子树完成遍历后的中序值，加入result，这个地方很巧
                else
                {
                    temp = tempStack.top();
                    result.push_back(temp->val);
                    temp = temp->right;
                    tempStack.pop();
                }
            }
        }
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */