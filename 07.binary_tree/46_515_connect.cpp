// https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/
#include <iostream>

using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        // 还是要处理一下空输入
        if (root == nullptr)
            return root;
        stack<Node *> layerStack{};
        layerStack.push(root);
        while (!layerStack.empty())
        {
            stack<Node *> hodor{};
            while (!layerStack.empty())
            {
                Node *temp = layerStack.top();
                layerStack.pop();
                // 直接指向stack不会正确赋值nullptr还会出现访问异常，用size处理一下比较好
                if (layerStack.size() > 0)
                    temp->next = layerStack.top();
                else
                    temp->next = nullptr;

                if (temp->left)
                    hodor.push(temp->left);
                if (temp->right)
                    hodor.push(temp->right);
            }
            while (!hodor.empty())
            {
                layerStack.push(hodor.top());
                hodor.pop();
            }
        }
        return root;
    }
};