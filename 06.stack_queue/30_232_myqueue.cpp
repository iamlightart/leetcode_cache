// https://leetcode.cn/problems/implement-queue-using-stacks/description/
// 2025-11-25
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
class MyQueue
{
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        s1.push(x);
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

    int pop()
    {
        int result = s2.top();
        s2.pop();
        return result;
    }

    int peek()
    {
        return s2.top();
    }

    bool empty()
    {
        return s2.empty();
    }
};

// Your MyQueue object will be instantiated and called as such:
int main()
{
    MyQueue *obj = new MyQueue();
    obj->push(x);
    int param_2 = obj->pop();
    int param_3 = obj->peek();
    bool param_4 = obj->empty();
}
