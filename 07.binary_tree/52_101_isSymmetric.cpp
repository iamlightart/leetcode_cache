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
// 优化掉头插效率就很高了，deque尽量不要用push_front
//  deque 不是 “连续内存数组”，而是由一个「中控数组」+多个固定大小的「分段数组」组成（可以理解为 “数组 + 动态的双向链表 ”）：
// 中控数组：[分段1地址, 分段2地址, 分段3地址]
//           ↓         ↓         ↓
//           [1,2,3]   [4,5,6]   [7,8,9]
// （每个分段大小固定，比如3个元素）
//
//  push_back（尾插）：优先往最后一个分段的尾部加元素，分段满了才新增一个分段 → 大概率命中 CPU 缓存，操作极快；
// 1. deque头插低效：操作首分段头部破坏CPU缓存空间局部性，缓存命中率暴跌(刚访问过的内存地址，其周边的地址会被缓存,尾插的操作路径刚好契合缓存的空间局部性)
// 2. deque头插低效：首分段满时触发中控数组头部插入，导致数组元素重排产生额外开销
// deque的pop_front()效率不低
// deque可以用下标遍历，效率可以，stack不能这样操作
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return false;
        if (root->left == nullptr && root->right == nullptr)
            return true;
        deque<TreeNode *> layerDeque{};
        layerDeque.push_back(root->left ? root->left : nullptr);
        layerDeque.push_back(root->right ? root->right : nullptr);
        while (!layerDeque.empty())
        {
            deque<TreeNode *> hodor{};
            for (int i = 0; i < layerDeque.size() / 2; i++)
            {
                TreeNode *curr_left = layerDeque[i];
                TreeNode *curr_right = layerDeque[layerDeque.size() - 1 - i];
                if (curr_left == curr_right)
                    continue;
                else if (curr_left != nullptr && curr_right == nullptr)
                    return false;
                else if (curr_left == nullptr && curr_right != nullptr)
                    return false;
                else if (curr_left->val != curr_right->val)
                    return false;
            }
            while (!layerDeque.empty())
            {
                TreeNode *temp = layerDeque.front();
                layerDeque.pop_front();
                if (temp != nullptr)
                {
                    hodor.push_back(temp->left ? temp->left : nullptr);
                    hodor.push_back(temp->right ? temp->right : nullptr);
                }
            }
            while (!hodor.empty())
            {
                layerDeque.push_back(hodor.front());
                hodor.pop_front();
            }
        }
        return true;
    };
};
// 用头插效率低，尝试优化
// class SlowSolution
// {
// public:
//     bool isSymmetric(TreeNode *root)
//     {
//         if (root == nullptr)
//             return false;
//         if (root->left == nullptr && root->right == nullptr)
//             return true;
//         deque<TreeNode *> layerDeque{};
//         layerDeque.push_front(root->left ? root->left : nullptr);
//         layerDeque.push_back(root->right ? root->right : nullptr);
//         while (!layerDeque.empty())
//         {
//             deque<TreeNode *> hodor{};
//             while (!layerDeque.empty())
//             {
//                 TreeNode *curr_left = layerDeque.front();
//                 TreeNode *curr_right = layerDeque.back();
//                 if (curr_left == nullptr && curr_right == nullptr)
//                 {
//                 }
//                 else if ((curr_left != nullptr) && (curr_right == nullptr) ||
//                          (curr_left == nullptr) && (curr_right != nullptr) ||
//                          curr_left->val != curr_right->val)
//                 {
//                     return false;
//                 }

//                 layerDeque.pop_front();
//                 layerDeque.pop_back();
//                 if (curr_left != nullptr)
//                 {
//                     hodor.push_front(curr_left->right ? curr_left->right : nullptr);
//                     hodor.push_front(curr_left->left ? curr_left->left : nullptr);
//                 }
//                 if (curr_right != nullptr)
//                 {
//                     hodor.push_back(curr_right->left ? curr_right->left : nullptr);
//                     hodor.push_back(curr_right->right ? curr_right->right : nullptr);
//                 }
//             }
//             while (!hodor.empty())
//             {
//                 layerDeque.push_back(hodor.front());
//                 hodor.pop_front();
//             }
//         }
//         return true;
//     };
// };