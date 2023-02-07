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

void mirror(Node *root, Node **mirr)
{
    if (root == nullptr)
        return;

    *mirr = new Node(root->data);

    mirror(root->left, &((*mirr)->right));
    mirror(root->right, &((*mirr)->left));
}

void mirrorRef(Node *root, Node *&mirr)
{
    if (root == nullptr)
        return;

    mirr = new Node(root->data);

    mirrorRef(root->left, mirr->right);
    mirrorRef(root->right, mirr->left);
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

    Node *m = nullptr;

    mirror(root, &m);

    inorder(root);
    cout << endl;

    inorder(m);
    cout << endl;

    Node *m2 = nullptr;

    mirrorRef(root, m2);
    inorder(m2);
    cout << endl;

    return 0;
}
