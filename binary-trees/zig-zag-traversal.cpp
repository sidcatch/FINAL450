#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node
{
  public:
    int data;
    Node *left, *right;
};

vector<int> zigZagTraversal(Node *root)
{
    if (root == NULL)
    {
        return {};
    }

    vector<int> ans;
    queue<Node *> q;
    q.push(root);
    bool flag = false;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();
            level.push_back(node->data);

            if (node->left != NULL)
            {
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                q.push(node->right);
            }
        }
        flag = !flag;
        if (flag == false)
        {
            reverse(level.begin(), level.end());
        }
        for (int i = 0; i < level.size(); i++)
        {
            ans.push_back(level[i]);
        }
    }
    return ans;
}

struct Node *newNode(int data)
{
    struct Node *node = new struct Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

int main()
{

    vector<int> v;

    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    cout << "ZigZag Order traversal of binary tree is \n";

    v = zigZagTraversal(root);

    for (int i = 0; i < v.size(); i++)

        cout << v[i] << " ";

    return 0;
}