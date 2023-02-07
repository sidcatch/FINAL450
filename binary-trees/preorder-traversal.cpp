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

void preorder(Node *root)
{

    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);

    preorder(root->right);
}

void preorderItr(Node *root)
{

    if (root == nullptr)
        return;

    stack<Node *> s;
    s.push(root);

    while (!s.empty())
    {

        Node *curr = s.top();
        cout << curr->data << " ";
        s.pop();

        if (curr->right)
            s.push(curr->right);
        if (curr->left)
            s.push(curr->left);
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Binary Tree In Order\n";

    preorder(root);
    cout << endl;
    preorderItr(root);

    return 0;
}
