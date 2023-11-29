#include <bits/stdc++.h>
using namespace std;

//see gfg for faster Algorithm
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

void printLevel(Node *root, int level);
int height(Node *node);

void printLevelOrder(Node *root)
{
    int h = height(root);
    int i;
    for (i = 0; i <= h; i++) //1 instead of 0, if counting nodes for height (instead of edges)
        printLevel(root, i);

    cout << endl;
}

void printLevel(Node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 0) //1 if counting nodes for height (instead of edges)
        cout << root->data << " ";
    else if (level > 0) //1 instead of 0, if counting nodes for height (instead of edges)
    {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

int height(Node *node)
{
    if (node == NULL)
        return -1; //0 instead of -1, if counting nodes for height (instead of edges)
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        /* use the larger one */
        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
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

    // cout << height(root) << endl;
    // printLevel(root, 2);

    // cout << endl;
    printLevelOrder(root);

    return 0;
}

// This code is contributed by rathbhupendra
