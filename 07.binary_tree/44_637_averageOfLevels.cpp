// https://leetcode.cn/problems/average-of-levels-in-binary-tree/description/
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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> result{};
        // 用一个deque处理感觉没有两个stack直观
        deque<TreeNode *> layerDeque{};
        if (root == nullptr)
            return result;
        else
        {
            layerDeque.push_back(root);
            layerDeque.push_back(nullptr);

            while (layerDeque.front() != nullptr)
            {
                int layer_counts = layerDeque.size() - 1;
                double layer_sum = 0;
                while (!layerDeque.empty())
                {
                    TreeNode *tempNode = layerDeque.front();
                    layerDeque.pop_front();
                    if (tempNode == nullptr)
                        break;
                    else
                    {
                        layer_sum += tempNode->val;
                        if (tempNode->left)
                            layerDeque.push_back(tempNode->left);
                        if (tempNode->right)
                            layerDeque.push_back(tempNode->right);
                    }
                }
                result.push_back(layer_sum / layer_counts);
                layerDeque.push_back(nullptr);
            }
        }
        // 总是忘记写返回值呢？😂
        return result;
    }
};