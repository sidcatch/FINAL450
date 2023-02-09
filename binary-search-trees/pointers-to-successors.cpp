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
        this->next = next;
    }
};

void createNextPointers(Node *root, Node *&prev, Node *&first)
{

    if (root == nullptr)
        return;

    createNextPointers(root->left, prev, first);

    if (prev)
        prev->next = root;

    if (!first)
        first = root;

    prev = root;

    createNextPointers(root->right, prev, first);
}

// bool createNextPointers(Node *root, Node *&prev)
// {
//     if (root == nullptr)
//         return true;

//     //Important don't return directly here!!
//     if (!createNextPointers(root->left, prev))
//         return false;

//     if (prev)
//         prev->next = root;

//     prev = root;

//     return createNextPointers(root->right, prev);
// }

void printInorder(Node *root)
{

    Node *prev = nullptr;
    Node *first = nullptr;

    createNextPointers(root, prev, first);

    while (first)
    {
        cout << first->data << " ";
        first = first->next;
    }

    cout << endl;
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

    printInorder(root);
    cout << endl;

    Node *root1 = new Node(50);
    root1->left = new Node(20);
    root1->right = new Node(60);
    root1->left->left = new Node(10);
    root1->left->right = new Node(30);
    root1->right->left = new Node(55);
    root1->right->right = new Node(70);

    printInorder(root1);
    cout << endl;

    return 0;
}
