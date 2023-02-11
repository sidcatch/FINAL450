//(q) Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.
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

void storeNodesData(Node *root, set<int> &nodesData)
{
    if (root == nullptr)
        return;

    storeNodesData(root->left, nodesData);

    nodesData.insert(root->data);

    storeNodesData(root->right, nodesData);
}

void createBST(Node *root, set<int>::iterator &it)
{
    if (root == nullptr)
        return;

    createBST(root->left, it);

    root->data = *it;

    it++;

    createBST(root->right, it);
}

void inorder(Node *root)
{

    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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

    inorder(root);
    cout << endl;

    set<int> nodesData;

    storeNodesData(root, nodesData);

    // set<int>::iterator it;

    set<int>::iterator it = nodesData.begin();

    createBST(root, it);

    inorder(root);
    cout << endl;

    return 0;
}
