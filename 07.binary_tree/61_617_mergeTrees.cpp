
// https://leetcode.cn/problems/merge-two-binary-trees/
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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {

        if (root1 == nullptr && root2 == nullptr)
            return nullptr;

        TreeNode *node = new TreeNode{};
        // 直接赋值就行了不需要merge到尾端
        if (root1 == nullptr)
            node = root2;

        else if (root2 == nullptr)
            node = root1;
        else
        {
            node->val = root1->val + root2->val;
            node->left = mergeTrees(root1->left, root2->left);
            node->right = mergeTrees(root1->right, root2->right);
        }

        return node;
    }
};