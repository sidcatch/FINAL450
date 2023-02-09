#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right, *next;

    Node(int data, Node *left = nullptr, Node *right = nullptr, Node *next = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

Node *lowestCommonAncestor(Node *root, int x, int y)
{
    while (root)
    {
        if (x < root->data && y < root->data)
            root = root->left;
        else if (x > root->data && y > root->data)
            root = root->right;

        else
            break;
    }

    return root;
}

void printLCA(Node *root, int x, int y)
{
    Node *lcs = lowestCommonAncestor(root, x, y);

    if (lcs)
        cout << "Lowest common ancestor of " << x << " and " << y << " is " << lcs->data << endl;
    else
        cout << "Lowest common ancestor of " << x << " and " << y << " is "
             << "not found" << endl;
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    cout << "Binary Search Tree \n";

    printLCA(root, 3, 6);
    printLCA(root, 3, 1);

    Node *root1 = new Node(50);
    root1->left = new Node(20);
    root1->right = new Node(60);
    root1->left->left = new Node(10);
    root1->left->right = new Node(30);
    root1->right->left = new Node(55);
    root1->right->right = new Node(70);

    return 0;
}
