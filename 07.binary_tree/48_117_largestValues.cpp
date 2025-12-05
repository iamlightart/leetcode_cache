// https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/
// identical to 116
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

class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> results{};
        stack<TreeNode *> layerStack{};
        if (root == nullptr)
            return results;
        else
        {
            layerStack.push(root);
            while (!layerStack.empty())
            {
                stack<TreeNode *> hodor{};
                int max = INT_MIN;
                while (!layerStack.empty())
                {
                    TreeNode *temp = layerStack.top();
                    layerStack.pop();
                    max = max < temp->val ? temp->val : max;
                    if (temp->left)
                        hodor.push(temp->left);
                    if (temp->right)
                        hodor.push(temp->right);
                }
                while (!hodor.empty())
                {
                    layerStack.push(hodor.top());
                    hodor.pop();
                };
                results.push_back(max);
            }
        }
        return results;
    }
};