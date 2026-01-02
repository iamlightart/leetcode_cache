
// https://leetcode.cn/problems/binary-tree-cameras/description/
// Definition for a binary tree node.
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
// 这题需要的是叶节点为空而非根节点。 叶节点一定有上层节点，
// 上层节点放摄像机结果一定优于叶节点放摄像机额
class Solution
{
public:
    int minCameraCover(TreeNode *root)
    {
    }
};
