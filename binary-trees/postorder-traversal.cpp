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

void postorder(Node *root)
{

    if (root == nullptr)
        return;

    postorder(root->left);

    postorder(root->right);
    cout << root->data << " ";
}

void postorderItr(Node *root)
{

    if (root == nullptr)
        return;

    stack<Node *> s;
    s.push(root);

    stack<Node *> out;

    while (!s.empty())
    {

        Node *curr = s.top();
        out.push(curr);
        s.pop();

        if (curr->left)
            s.push(curr->left);
        if (curr->right)
            s.push(curr->right);
    }
    while (!out.empty())
    {

        Node *curr = out.top();
        cout << curr->data << " ";
        out.pop();
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

    postorder(root);
    cout << endl;
    postorderItr(root);

    return 0;
}
