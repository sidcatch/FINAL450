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

void morrisTraversal(Node *root)
{
    if (root == nullptr)
        return;

    Node *curr = root;

    while (curr)
    {

        if (curr->left == nullptr)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            Node *pre = curr->left;
            while (pre->right != nullptr && pre->right != curr)
                pre = pre->right;

            if (pre->right == nullptr)
            {
                pre->right = curr;
                curr = curr->left;
            }
            else
            {
                pre->right = nullptr;
                cout << curr->data << " ";
                curr = curr->right;
            }
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

    morrisTraversal(root);
    cout << endl;
    inorder(root);
    cout << endl;

    return 0;
}
