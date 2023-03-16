#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    // int lisSizeInc, lisSizeExc; // With this we won't need copyStructure()!

    Node(int data, Node *left = nullptr, Node *right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

void copyStructure(Node *root, Node *&c)
{
    if (root == nullptr)
        return;

    c = new Node(-1);

    copyStructure(root->left, c->left);
    copyStructure(root->right, c->right);
}

void lis(Node *&root, Node *&dpRootChosen, Node *&dpRootNotChosen)
{
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr)
    {
        dpRootChosen->data = 1;
        dpRootNotChosen->data = 0;
        return;
    }

    // cout << dpRootChosen->data << " ";
    // if (dpRootChosen->data != -1)
    //     return;

    lis(root->left, dpRootChosen->left, dpRootNotChosen->left);
    lis(root->right, dpRootChosen->right, dpRootNotChosen->right);

    if (root->left && root->right)
    {
        dpRootChosen->data = dpRootNotChosen->left->data + dpRootNotChosen->right->data + 1;
        dpRootNotChosen->data = max(dpRootChosen->left->data, dpRootNotChosen->left->data) + max(dpRootChosen->right->data, dpRootNotChosen->right->data);
        return;
    }
    if (root->left)
    {
        dpRootChosen->data = dpRootNotChosen->left->data + 1;
        dpRootNotChosen->data = max(dpRootChosen->left->data, dpRootNotChosen->left->data);
        return;
    }
    if (root->right)
    {
        dpRootChosen->data = dpRootNotChosen->right->data + 1;
        dpRootNotChosen->data = max(dpRootChosen->right->data, dpRootNotChosen->right->data);
        return;
    }
}

int lis(Node *root)
{

    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return 1;

    Node *dpRootChosen, *dpRootNotChosen;
    copyStructure(root, dpRootChosen);
    copyStructure(root, dpRootNotChosen);

    lis(root, dpRootChosen, dpRootNotChosen);

    return max(dpRootChosen->data, dpRootNotChosen->data);
}

int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right = new Node(22);
    root->right->right = new Node(25);

    cout << lis(root) << endl;

    return 0;
}
