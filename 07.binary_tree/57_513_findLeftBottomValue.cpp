// https://leetcode.cn/problems/find-bottom-left-tree-value/
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
// 优化层序，用queue来控制当前层，记录一个size处理for，这样更加直观，效率100%了
class Solution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        // 二叉树假设至少有一个节点
        if (root->left == nullptr && root->right == nullptr)
            return root->val;
        else
        {
            queue<TreeNode *> layerQueue{};
            layerQueue.push(root);
            TreeNode *result{};
            int layer_size = 1;
            while (layer_size != 0)
            {
                result = layerQueue.front();
                int ps_count = layer_size;
                layer_size = 0;
                // 不要在for里处理栈，lifo导致把下一层的数提前弹出去了
                for (int i = 1; i <= ps_count; i++)
                {
                    TreeNode *temp = layerQueue.front();
                    layerQueue.pop();
                    if (temp->left)
                    {
                        layerQueue.push(temp->left);
                        layer_size++;
                    }
                    if (temp->right)
                    {
                        layerQueue.push(temp->right);
                        layer_size++;
                    }
                }
            }
            return result->val;
        }
    }
};
// stack相互转换效率低，只打败了5%。存一个状态比反复计算效率高很多
// （我愿意用两个stack互换是一位这样可以不用关注每层的size，其实提前取一下就可以了）
class Solution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        // 二叉树假设至少有一个节点
        if (root->left == nullptr && root->right == nullptr)
            return root->val;
        else
        {
            stack<TreeNode *> layerQueue{};
            layerQueue.push(root);
            TreeNode *result{};
            while (!layerQueue.empty())
            {
                result = layerQueue.top();
                stack<TreeNode *> hodor{};
                while (!layerQueue.empty())
                {
                    TreeNode *temp = layerQueue.top();
                    layerQueue.pop();
                    if (temp->left)
                        hodor.push(temp->left);
                    if (temp->right)
                        hodor.push(temp->right);
                }
                while (!hodor.empty())
                {
                    layerQueue.push(hodor.top());
                    hodor.pop();
                }
            }
            return result->val;
        }
    }
};