// https: // leetcode.cn/problems/implement-stack-using-queues/description/
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
// 注意front不包含pop的动作，和stack的peek一样只是看一下数据
class MyStack
{
    queue<int> q1;
    queue<int> q2;
    int count;

public:
    MyStack()
    {
        count = 0;
    }

    void push(int x)
    {
        q1.push(x);
        count++;
    }

    int pop()
    {
        for (int i = 0; i < count - 1; i++)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int result = q1.front();
        q1.pop();
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        count--;
        return result;
    }

    int top()
    {
        for (int i = 0; i < count - 1; i++)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int result = q1.front();
        q1.pop();
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        q1.push(result);
        return result;
    }

    bool empty()
    {
        return q1.empty() && q2.empty();
    }
};

int main()
{
    MyStack *obj = new MyStack();
    obj->push(1);
    obj->push(2);
    int param_2 = obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();
    cout << param_2 << param_3 << param_4;
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */