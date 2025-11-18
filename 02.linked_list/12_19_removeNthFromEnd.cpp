// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
// 2025年11月14日
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

// Definition for singly-linked list.
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fake_head = new ListNode(0);
        fake_head->next = head;

        ListNode *checker = head;
        ListNode *deleter = fake_head;
        for (size_t i = 1; i <= n; i++)
        {
            if (checker == nullptr)
                return head;
            checker = checker->next;
        }
        while (checker != nullptr)
        {
            checker = checker->next;
            deleter = deleter->next;
        }

        ListNode *temp = deleter->next;
        deleter->next = (deleter->next != nullptr) ? deleter->next->next : nullptr;
        if (temp != nullptr)
            delete temp;
        // 不能返回head，因为这时候head指向的值已经被delete temp删除掉，
        // 现在head是野指针，而fake_head->next是空指针
        return fake_head->next;
    }
};