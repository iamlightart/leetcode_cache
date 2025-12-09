// https://leetcode.cn/problems/maximum-binary-tree/submissions/683646205/
//  Definition for a binary tree node.
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
private:
    int get_max(vector<int> &nums, int start, int end)
    {
        int max_val = INT_MIN;
        int result = -1;
        for (int i = start; i <= end; i++)
        {
            if (nums[i] > max_val)
            {
                max_val = nums[i];
                result = i;
            }
        }

        return result;
    }
    TreeNode *constructImpl(vector<int> &nums, int start, int end)
    {
        int max_idx = get_max(nums, start, end);
        TreeNode *node = new TreeNode{nums[max_idx]};
        int l_0 = start;
        int l_1 = max_idx - 1;
        int r_0 = max_idx + 1;
        int r_1 = end;
        if (l_0 <= l_1)
            node->left = constructImpl(nums, l_0, l_1);
        if (r_0 <= r_1)
            node->right = constructImpl(nums, r_0, r_1);
        return node;
    };

public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.size() == 0)
            return nullptr;
        return constructImpl(nums, 0, nums.size() - 1);
    }
};

int main()
{
    vector<int> nums = {3, 2, 1, 6, 0, 5};
    Solution s;
    s.constructMaximumBinaryTree(nums);
}