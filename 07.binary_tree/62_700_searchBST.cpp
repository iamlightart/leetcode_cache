// https://leetcode.cn/problems/search-in-a-binary-search-tree/
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
// 递归简单，可以尝试用while+stack手动控制
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val == val)
            return root;
        else
        {
            TreeNode *l_res = searchBST(root->left, val);
            TreeNode *r_res = searchBST(root->right, val);
            return l_res != nullptr ? l_res : r_res;
        }
    }
};