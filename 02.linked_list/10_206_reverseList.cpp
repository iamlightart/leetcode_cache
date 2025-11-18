// https://leetcode.cn/problems/reverse-linked-list/description/
// 2025年11月14日 11:08:27
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

//   Definition for singly-linked list.
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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return head;

        ListNode *prev = nullptr;
        ListNode *left = head;
        ListNode *right = head->next;
        // 注意需要让head.next指向nullptr，不然链表本身是成环的，测试用例会报错
        head->next = nullptr;
        while (right != nullptr)
        {
            prev = left;
            left = right;
            right = right->next;
            left->next = prev;
        }
        return left;
    }
};