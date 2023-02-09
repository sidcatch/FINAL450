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

Node *treeFromPreOrderUtil(int preOrder[], int size, int *preOrderIndex, int key, int max, int min)
{
    if (*preOrderIndex >= size)
        return nullptr;

    Node *root = nullptr;

    if (key > min && key < max)
    {
        root = new Node(key);
        // *preOrderIndex = *preOrderIndex + 1;
        (*preOrderIndex)++; //Note: The ++ has equal precedence with the * and the associativity is right-to-left.

        if (*preOrderIndex < size)
        {
            root->left = treeFromPreOrderUtil(preOrder, size, preOrderIndex, preOrder[*preOrderIndex], key, min);
        }

        if (*preOrderIndex < size)
        {
            root->right = treeFromPreOrderUtil(preOrder, size, preOrderIndex, preOrder[*preOrderIndex], max, key);
        }
    }

    return root;
}

Node *treeFromPreOrder(int preOrder[], int size)
{
    if (size == 0)
        return nullptr;
    int preOrderIndex = 0;
    return treeFromPreOrderUtil(preOrder, size, &preOrderIndex, preOrder[preOrderIndex], INT_MAX, INT_MIN);
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

    int preOrder[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof(preOrder) / sizeof(preOrder[0]);

    Node *root = treeFromPreOrder(preOrder, size);

    inorder(root);

    return 0;
}
