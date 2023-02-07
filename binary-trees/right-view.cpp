#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int data, Node *left = nullptr, Node *right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

void rightView(Node *root, int level, int *maxLevel)
{
    if (root == nullptr)
        return;

    if (*maxLevel < level)
    {
        cout << root->data << " ";
        *maxLevel = level;
    }
    rightView(root->right, level + 1, maxLevel);
    rightView(root->left, level + 1, maxLevel);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Binary Tree Left view\n";

    int maxLevel = 0;

    rightView(root, 1, &maxLevel);

    return 0;
}
