// https://leetcode.cn/problems/swap-nodes-in-pairs/
// 2025年11月14日
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        // 注意空值输入需要单独处理
        if (head == nullptr)
            return head;
        ListNode *left = head;
        ListNode *right = head->next;
        if (right == nullptr)
            return head;

        while (right != nullptr)
        {
            int temp = left->val;
            left->val = right->val;
            // 注意反转值的时候不要弄错了成left->val
            right->val = temp;
            left = right->next;
            if (left == nullptr)
                return head;
            right = left->next;
        }
        return head;
    }
};
