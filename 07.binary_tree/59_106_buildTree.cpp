// https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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

class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {

        return buildTreeImpl(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    TreeNode *buildTreeImpl(vector<int> &inorder, vector<int> &postorder, int i_start, int i_end, int p_start, int p_end)
    {
        TreeNode *node = new TreeNode(postorder[p_end]);
        // 计算inorder中的root值，存起来，左右各自加减1，最不容易算错
        int root_index = -1;
        // 每次在子区间确定root_index的值会影响效率，
        // 但其实题目存在隐含条件“中序 + 后序，若数组允许重复值 ⇒ 一般无法唯一重构二叉树”
        // 所以可以在算法开始，先用unordered_map缓存所有val的rootindex<val,index>
        // 这样可以避免在每一次构建数组是还需要重新for循环，直接在表中取出index即可
        // 我的这种防御性思路属于对重复值的直觉
        //  可以举出反例在重复数的情况下可能出现二义性(inorder[1,1,1,1,1,1],postorder[1,1,1,1,1,1]),
        // 但无法论证，是不是所有有重复值的中后序数组，都无法正确构建二叉树
        for (root_index = i_start; root_index <= i_end; root_index++)
        {
            if (inorder[root_index] == node->val)
                break;
        }
        int left_i_start = i_start;
        int left_i_end = root_index - 1;
        int right_i_start = root_index + 1;
        int right_i_end = i_end;

        int left_p_start = p_start;
        // 注意这里不需要另外+1，因为都是数组下标
        int left_p_end = p_start + left_i_end - left_i_start;
        int right_p_start = left_p_end + 1;
        int right_p_end = p_end - 1;
        if (left_i_start <= left_i_end && left_p_start <= left_p_end)
            node->left = buildTreeImpl(inorder, postorder, left_i_start, left_i_end, left_p_start, left_p_end);
        if (right_i_start <= right_i_end && right_p_start <= right_p_end)
            node->right = buildTreeImpl(inorder, postorder, right_i_start, right_i_end, right_p_start, right_p_end);
        return node;
    }
};