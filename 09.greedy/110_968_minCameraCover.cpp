
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
// 自己尝试写一版本标准解
//  1️⃣ 相机只放在能直接覆盖未覆盖子节点的节点上。
//  2️⃣ 已被覆盖且子节点无未覆盖需求的节点永远不会放相机。
class Solution
// 0：未被覆盖（需要父节点放相机）
// 1：当前节点有相机
// 2：当前节点已被覆盖（但自己没有相机）
{
private:
    int result = 0;

public:
    int minCameraCover(TreeNode *root)
    {
        // ❌这种判断方法是错的，会产生覆盖不全的情况
        //  if (!root->left && !root->right)
        //      return 1;
        //  coverImpl(root);
        // ✅要用root节点返回值的状态来判断，root是否被覆盖，如果为0则加一个值，就可以保证[0,null,0,null,0,null,0] 这样的解被覆盖了
        // 这里很取巧，如果只考虑了root为独立节点的情况，会忽略root不为空节点，但也没有被覆盖的情况
        if (coverImpl(root) == 0)
            result++;
        return result;
    }
    int coverImpl(TreeNode *node)
    {
        // 当为空节点时，假定此节点为被覆盖切没有相机的状态，这样不会影响真正的节点
        if (!node)
            return 2;
        int left = coverImpl(node->left);
        int right = coverImpl(node->right);
        // 若两个子节点都没被覆盖且没有相机，当前节点添加一个相机，此方式满足性质1️⃣
        if (left == 0 || right == 0)
        {
            result++;
            return 1;
        }
        // 若两个字节点任何一个有相机，则当前的节点为被覆盖但无相机
        if (left == 1 || right == 1)
        {
            return 2;
        };
        // 其他情况，即两个子节点都为2，证明两个子节点都被覆盖切没有相机，那在此节点不放相机让上面的父节点放相机才更优1️⃣
        return 0;
    };
};
// 标准解
// 0：未被覆盖（需要父节点放相机）
// 1：当前节点有相机
// 2：当前节点已被覆盖（但自己没有相机）
class gptSolution
{
public:
    int result = 0;

    int minCameraCover(TreeNode *root)
    {
        // 如果根节点最终仍然未覆盖，需要补一个相机
        if (dfs(root) == 0)
        {
            result++;
        }
        return result;
    }

    int dfs(TreeNode *node)
    {
        if (!node)
        {
            // 空节点视为“已覆盖”
            return 2;
        }

        int left = dfs(node->left);
        int right = dfs(node->right);

        // 情况 1：只要有一个子节点未覆盖，当前节点必须放相机
        if (left == 0 || right == 0)
        {
            result++;
            return 1;
        }

        // 情况 2：只要有一个子节点有相机，当前节点就被覆盖
        if (left == 1 || right == 1)
        {
            return 2;
        }

        // 情况 3：左右子节点都被覆盖，但都没有相机
        // 那当前节点就是“未覆盖”，交给父节点处理
        return 0;
    }
};
// 🌟这题需要的是叶节点为空而非根节点。 叶节点一定有上层节点，
// 上层节点放摄像机结果一定优于叶节点放摄像机额
// 下面的做法错了，状态转移的思路不对，[0,0,null,null,0,0,null,null,0,0] 会错误
class wrongSolution
{
private:
    int result = 0;

public:
    int minCameraCover(TreeNode *root)
    {
        if (!root->left && !root->right)
            return 1;
        coverImpl(root);
        return result;
    }
    int coverImpl(TreeNode *node)
    {
        if (!node)
            return 0;
        if (!node->left && !node->right)
            return 3;
        int back_tracking = coverImpl(node->left) + coverImpl(node->right);
        if (back_tracking >= 3)
        {
            result++;
            return 1;
        }
        if (back_tracking == 0)
        {
            result++;
            return 1;
        }

        return 0;
    };
};
