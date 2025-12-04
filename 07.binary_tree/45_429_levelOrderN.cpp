// https://leetcode.cn/problems/n-ary-tree-level-order-traversal/
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <unordered_set>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> result{};
        stack<Node *> tempStack{};
        if (root == nullptr)
            return result;
        else
        {
            tempStack.push(root);
            while (!tempStack.empty())
            {
                vector<int> layerResult;
                stack<Node *> layerStack{};
                while (!tempStack.empty())
                {
                    Node *tempNode = tempStack.top();
                    if (tempNode->children.size() > 0)
                    {
                        for (Node *sub : tempNode->children)
                        {
                            layerStack.push(sub);
                        }
                    }
                    // 不要忘记pop
                    tempStack.pop();
                    layerResult.push_back(tempNode->val);
                }
                while (!layerStack.empty())
                {
                    tempStack.push(layerStack.top());
                    layerStack.pop();
                }
                result.push_back(layerResult);
            }
        }
        return result;
    }
};