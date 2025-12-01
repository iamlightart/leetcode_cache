// https://leetcode.cn/problems/binary-tree-preorder-traversal/
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
// 迭代遍历
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        // stack中应该存TreeNode的指针
        stack<TreeNode *> tempStack;
        preOrder(root, result, tempStack);
        return result;
    }
    void preOrder(TreeNode *node, vector<int> &result, stack<TreeNode *> &tempStack)
    {
        // 需要处理一下空值
        if (node == nullptr)
            return;
        tempStack.push(node);
        while (!tempStack.empty())
        {
            TreeNode *curr = tempStack.top();
            tempStack.pop();
            result.push_back(curr->val);
            // stack的数据是反过来的，先处理的要后入栈顺序才正确
            if (curr->right)
                tempStack.push(curr->right);
            if (curr->left)
                tempStack.push(curr->left);
        }
    }
};
