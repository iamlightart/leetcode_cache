// https://leetcode.cn/problems/binary-tree-postorder-traversal/
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
// 后序是中点在最后面
// 遍历方法,和前序类似，但是是输出中右左，然后把答案完全反过来，就是左右中
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {

        vector<int> result;
        stack<TreeNode *> tempStack;
        postOrder(root, result, tempStack);
        reverse(result.begin(), result.end());
        return result;
    }
    void postOrder(TreeNode *node, vector<int> &result, stack<TreeNode *> &tempStack)
    {
        if (node == nullptr)
            return;
        else
        {
            tempStack.push(node);
            while (!tempStack.empty())
            {
                TreeNode *temp = tempStack.top();
                result.push_back(temp->val);
                tempStack.pop();
                if (temp->left)
                    tempStack.push(temp->left);
                if (temp->right)
                {
                    tempStack.push(temp->right);
                }
            }
        }
    };
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