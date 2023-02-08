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

bool isBST(Node *root, int min, int max)
{

    if (root == nullptr)
        return true;

    if (root->data >= max || root->data <= min)
        return false;

    return isBST(root->left, min, root->data) && isBST(root->right, root->data, max);
}

bool isBST2(Node *root, Node *&prev)
{
    if (root == nullptr)
        return true;

    //Important don't return directly here!!
    if (!isBST2(root->left, prev))
        return false;

    if (prev != nullptr && root->data <= prev->data)
        return false;

    prev = root;

    return isBST2(root->right, prev);
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    root->left->left->left = new Node(7);

    cout << "Binary Search Tree \n";

    cout << isBST(root, INT_MIN, INT_MAX) << endl;

    Node *prev = nullptr;
    cout << isBST2(root, prev) << endl;

    Node *root1 = new Node(50);
    root1->left = new Node(20);
    root1->right = new Node(60);
    root1->left->left = new Node(10);
    root1->left->right = new Node(30);
    root1->right->left = new Node(55);
    root1->right->right = new Node(70);

    cout << isBST(root1, INT_MIN, INT_MAX) << endl;

    Node *prev2 = nullptr;
    cout << isBST2(root1, prev2) << endl;

    return 0;
}
