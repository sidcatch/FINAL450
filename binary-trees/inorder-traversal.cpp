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

void inorder(Node *root)
{

    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void inorderItr(Node *root)
{

    if (root == nullptr)
        return;

    stack<Node *> s;
    Node *curr = root;

    while (!s.empty() || curr != nullptr)
    {

        if (curr != nullptr)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = s.top();
            cout << curr->data << " ";
            s.pop();

            curr = curr->right;
        }
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

    inorder(root);
    cout << endl;
    inorderItr(root);

    return 0;
}
