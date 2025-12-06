
//   Definition for a binary tree node.
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
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        else
        {
            int count = 0;
            countNodesImpl(root, count);
            return count;
        }
    }

private:
    void countNodesImpl(TreeNode *node, int &count)
    {
        count++;
        if (node->left)
            countNodesImpl(node->left, count);
        if (node->right)
            countNodesImpl(node->right, count);
    }
};