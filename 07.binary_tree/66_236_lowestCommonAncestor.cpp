#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> path_p = get_path(root, p);
        vector<TreeNode *> path_q = get_path(root, q);
        int length = min(path_p.size(), path_q.size());
        for (int i = 0; i < length - 1; i++)
        {
            if (path_p[i] != path_q[i])
                return path_p[i - 1];
        }
    }

private:
    vector<TreeNode *> get_path(TreeNode *root, TreeNode *end)
    {
        vector<TreeNode *> path_hodor{};
    };
};