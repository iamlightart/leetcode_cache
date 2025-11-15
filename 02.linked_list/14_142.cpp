// https://leetcode.cn/problems/linked-list-cycle-ii/description/
// 2025年11月15日
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <math.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
快慢指针的本质是个数学问题，file://./imgs/14_142.png
快指针以慢指针二倍的速度进入环 则第一次相遇
vt = x + y; 2vt = x + n(y+z) + y;
x= (n-1)(y+z)+z;
所以 x和z之间差了(n-1)圈的整数倍距离
这时只要在第一次相遇点和头节点分别启动一个匀速的指针
两个指针相遇时分别走过了x和z，正好在入口相遇
 */

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // 若head只有一个node或者本身为空则直接返回
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }
        // 不要忘记fast->next 为nullptr的情况，若忘记了则会在return条件上出现问题
        // while是因为fast->next == nullptr终止的，但此处没有判断fast->next == nullptr直接return
        // 导致后面的slow指针会继续向下走出现nullptr的西情况
        if (fast == nullptr || fast->next == nullptr)
            return nullptr;

        ListNode *outer = head;
        ListNode *inner = slow;
        while (outer != inner)
        {
            outer = outer->next;
            inner = inner->next;
        }
        return outer;
    }
};
//  我最开始用set存经过节点，此解法内存和执行效率都比较低
class DeprecatedSolution1
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        int pos = 0;
        set<ListNode *> pass_node{};
        while (head != nullptr)
        {
            if (pass_node.find(head) != pass_node.end())
                // 注意看题干返回值是node指针
                return head;
            else
                pass_node.insert(head);
            head = head->next;
            pos++;
        }
        // 注意看题干返回值是node指针
        return nullptr;
    }
};
