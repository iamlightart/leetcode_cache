// https : // leetcode.cn/problems/binary-tree-right-side-view/
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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result{};
        stack<TreeNode *> tempStack{};
        if (root == nullptr)
            return result;
        else
        {
            tempStack.push(root);
            stack<TreeNode *> layerStack;
            while (!tempStack.empty())
            {
                TreeNode *tempNode{};
                while (!tempStack.empty())
                {
                    tempNode = tempStack.top();
                    if (tempNode->left)
                        layerStack.push(tempNode->left);
                    if (tempNode->right)
                        layerStack.push(tempNode->right);
                    tempStack.pop();
                }
                while (!layerStack.empty())
                {
                    tempStack.push(layerStack.top());
                    layerStack.pop();
                }
                result.push_back(tempNode->val);
            }
        }
        return result;
    }
};