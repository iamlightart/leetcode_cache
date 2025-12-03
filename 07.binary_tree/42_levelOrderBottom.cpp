// https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/
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
class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> result{};
        if (root == nullptr)
            return result;
        stack<TreeNode *> tempStack{};
        tempStack.push(root);
        while (!tempStack.empty())
        {
            stack<TreeNode *> layerStack{};
            while (!tempStack.empty())
            {
                layerStack.push(tempStack.top());
                tempStack.pop();
            }
            vector<int> layerResult{};
            while (!layerStack.empty())
            {
                TreeNode *tempNode = layerStack.top();
                layerResult.push_back(tempNode->val);
                if (tempNode->left)
                    tempStack.push(tempNode->left);
                if (tempNode->right)
                    tempStack.push(tempNode->right);
                layerStack.pop();
            }
            result.push_back(layerResult);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};