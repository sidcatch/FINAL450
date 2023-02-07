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

int diameter(Node *root, int *height)
{
    if (root == nullptr)
    {
        *height = 0;
        return 0;
    }

    int lh = 0, rh = 0;

    int lDiameter = diameter(root->left, &lh);
    int rDiameter = diameter(root->right, &rh);

    *height = max(lh, rh) + 1;

    return max(lh + rh + 1, max(lDiameter, rDiameter));
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Binary Tree diameter\n";

    int height = 0;
    cout << diameter(root, &height);

    return 0;
}
