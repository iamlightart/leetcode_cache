#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

// https://leetcode.cn/problems/remove-linked-list-elements/

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
    ListNode *removeElements(ListNode *head, int val)

    {
        // 栈上创建 fake_head（语法合法，但逻辑错误）因为如果返回值里面有了堆上的地址，
        // ListNode fake_head(0, head); 非常不建议的写法
        // 在堆上创建节点，可以正确的管理s
        ListNode *fake_head = new ListNode(0, head);
        ListNode *prev = fake_head;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            if (curr->val == val)
            {
                curr = curr->next;
                delete prev->next;
                prev->next = curr;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        ListNode *result = fake_head->next;
        delete fake_head;
        return result;
    }
};