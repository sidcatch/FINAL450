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

bool isBalanced(Node *root, int *height)
{
    static bool ans = true;

    if (root == nullptr)
        return true;

    int lh = 0, rh = 0;

    isBalanced(root->left, &lh);
    isBalanced(root->right, &rh);

    *height = max(lh, rh) + 1;

    if (abs(lh - rh) > 1)
    {
        ans = false;
        return false;
    }
    else
        return ans && true;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // root->left->left->left = new Node(6);

    cout << "Binary Tree \n";

    int height = 0;
    cout << isBalanced(root, &height);

    return 0;
}
