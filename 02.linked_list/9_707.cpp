#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

// https://leetcode.cn/problems/design-linked-list/description/
// 2025年11月13日 16:14:16

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

class MyLinkedList
{
private:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int val = 0) : val(val), next(nullptr) {}
    };
    ListNode *fake_head;
    // 可以创建要给用来给linkedlist长度计数的值，后面的各种边界值判定只需要先 index<size-1 即可，
    // 这个题解额外处理了每个边界值
    int size = 0;

public:
    MyLinkedList()
    {
        fake_head = new ListNode(-1);
        // 错误：创建的应该是空链表，没有额外的节点
        //   fake_head->next = new ListNode(0);
    }

    int get(int index)
    {
        if (fake_head->next == nullptr)
            return -1;
        // leetcode 不接受抛出异常
        // throw runtime_error("list is blank");
        ListNode *curr = fake_head->next;
        int count = 0;
        while (curr != nullptr && count < index)
        {
            curr = curr->next;
            count++;
        }
        if (curr == nullptr)
            return -1;
        // leetcode 不接受抛出异常
        // throw runtime_error("index out of bounds");
        return curr->val;
    }

    void addAtHead(int val)
    {
        ListNode *curr = new ListNode(val);
        curr->next = fake_head->next;
        fake_head->next = curr;
    }

    void addAtTail(int val)
    {
        ListNode *curr = fake_head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = new ListNode(val);
    }

    void addAtIndex(int index, int val)
    {
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        else
        {
            ListNode *prev = fake_head->next;
            if (prev == nullptr)
                return;
            ListNode *curr = fake_head->next->next;
            int count = 1;
            while (curr != nullptr && count < index)
            {
                prev = prev->next;
                curr = curr->next;
                count++;
            }
            if (count < index)
                return;
            // throw runtime_error("index out of bounds");
            ListNode *new_node = new ListNode(val);
            prev->next = new_node;
            new_node->next = curr;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index == 0)
        {
            if (fake_head->next == nullptr)
                return;
            ListNode *old_head = fake_head->next;
            fake_head->next = fake_head->next->next;
            delete old_head;
        }
        else
        {
            ListNode *prev = fake_head->next;
            ListNode *curr = fake_head->next->next;
            int count = 1;
            while (curr != nullptr && count < index)
            {
                prev = prev->next;
                curr = curr->next;
                count++;
            }
            if (curr == nullptr)
                return;
            prev->next = curr->next;
            delete curr;
        }
    }
};
