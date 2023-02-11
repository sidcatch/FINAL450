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

int height(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        int lHeight = height(root->left);
        int rHeight = height(root->right);

        if (lHeight > rHeight)
            return lHeight + 1;
        else
            return rHeight + 1;
    }
}

void inorder(Node *root, vector<int> &ordered)
{

    if (root == nullptr)
        return;

    inorder(root->left, ordered);
    cout << root->data << " ";
    ordered.push_back(root->data);
    inorder(root->right, ordered);
}

Node *balancedBSTFromInOrder(int inOrder[], int start, int end)
{

    if (start > end)
        return nullptr;

    Node *root = nullptr;

    int mid = (start + end) / 2;

    root = new Node(inOrder[mid]);

    root->left = balancedBSTFromInOrder(inOrder, start, mid - 1);
    root->right = balancedBSTFromInOrder(inOrder, mid + 1, end);

    return root;
}

Node *balancedBSTFromInOrder(vector<int> inOrder)
{

    int *arr = new int[inOrder.size()];
    copy(inOrder.begin(), inOrder.end(), arr);

    return balancedBSTFromInOrder(arr, 0, inOrder.size() - 1);
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    root->right->right->right = new Node(7);

    root->right->right->right->right = new Node(8);
    root->right->right->right->right->right = new Node(9);

    cout << height(root) << endl;

    vector<int> ordered;
    inorder(root, ordered);
    cout << endl;

    Node *root1 = balancedBSTFromInOrder(ordered);
    cout << height(root1) << endl;
    inorder(root1, ordered);
    cout << endl;

    return 0;
}
