// https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/description/
// 2025年11月15日
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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    int check_length(ListNode *head)
    {
        int result = 0;
        while (head != nullptr)
        {
            head = head->next;
            result++;
        };
        return result;
    }
    void move_start(ListNode *&head, int len)
    {
        for (size_t i = 0; i < len; i++)
        {
            head = head->next;
        }
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // 注意空值的处理
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        int a_length = check_length(headA);
        int b_length = check_length(headB);
        // 函数内自己复制一份传入的指针再挪动，这样更规范不会改变传入指针的指向
        ListNode *pA = headA;
        ListNode *pB = headB;
        if (a_length > b_length)
            move_start(pA, a_length - b_length);
        else
            move_start(pB, b_length - a_length);
        while (pA != nullptr)
        {
            if (pA == pB)
                return pA;
            // 写题解的时候忘记挪动值了导致提交失败
            pA = pA->next;
            pB = pB->next;
        }
        return nullptr;
    }
};