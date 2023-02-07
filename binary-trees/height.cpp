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

/* Driver code*/
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Height of the tree: " << height(root) << endl;

    return 0;
}

// This code is contributed by rathbhupendra
