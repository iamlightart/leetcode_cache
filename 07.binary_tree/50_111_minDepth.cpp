// https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
//    Definition for a binary tree node.
#include <iostream>
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

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        int result = 0;
        if (root == nullptr)
            return result;
        else
        {
            stack<TreeNode *> layerStack{};
            layerStack.push(root);
            while (!layerStack.empty())
            {
                result++;
                stack<TreeNode *> hodor{};
                while (!layerStack.empty())
                {
                    TreeNode *temp = layerStack.top();
                    layerStack.pop();
                    if (temp->left == nullptr && temp->right == nullptr)
                        return result;
                    else
                    {
                        if (temp->left)
                            hodor.push(temp->left);
                        if (temp->right)
                            hodor.push(temp->right);
                    }
                }
                while (!hodor.empty())
                {
                    layerStack.push(hodor.top());
                    hodor.pop();
                }
            }
        }
        return result;
    }
};