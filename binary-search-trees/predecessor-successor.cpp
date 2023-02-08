#include <bits/stdc++.h>
using namespace std;

struct Node;
void printPredSucc(Node *, Node *, int);

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

Node *findMin(Node *root)
{
    if (root == nullptr || root->left == nullptr)
        return root;

    else
        return findMin(root->left);
}

Node *findMax(Node *root)
{
    if (root == nullptr || root->right == nullptr)
        return root;

    else
        return findMin(root->right);
}

void findPredSuccUtil(Node *root, Node *&pred, Node *&succ, int x)
{
    if (root == nullptr)
    {

        return;
    }

    if (root->data == x)
    {
        if (root->left)
            pred = findMax(root->left);
        if (root->right)
            succ = findMin(root->right);
    }

    if (x < root->data)
    {
        succ = root;
        findPredSuccUtil(root->left, pred, succ, x);
    }

    if (x > root->data)
    {
        pred = root;
        findPredSuccUtil(root->right, pred, succ, x);
    }
}

void findPredSuccUtilItr(Node *root, Node *&pred, Node *&succ, int x)
{
    if (root == nullptr)
        return;

    Node *temp1 = root;

    while (temp1)
    {
        if (x < temp1->data)
        {
            succ = temp1;
            temp1 = temp1->left;
        }
        else
            temp1 = temp1->right;
    }

    Node *temp2 = root;

    while (temp2)
    {
        if (x > temp2->data)
        {
            pred = temp2;
            temp2 = temp2->right;
        }
        else
            temp2 = temp2->left;
    }
}

void printPredSucc(Node *pred, Node *succ, int x)
{
    if (pred)
        cout << "Predecessor of " << x << " is " << pred->data << endl;
    else
        cout << "Predecessor of " << x << " is "
             << "not found" << endl;
    if (succ)
        cout << "Successor of " << x << " is " << succ->data << endl;
    else
        cout << "Successor of " << x << " is "
             << "not found" << endl;
}

void findPredSucc(Node *root, int x)
{
    Node *pred = nullptr;
    Node *succ = nullptr;

    findPredSuccUtil(root, pred, succ, x);
    printPredSucc(pred, succ, x);
}

void findPredSuccItr(Node *root, int x)
{
    Node *pred = nullptr;
    Node *succ = nullptr;

    findPredSuccUtilItr(root, pred, succ, x);
    printPredSucc(pred, succ, x);
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

    findPredSucc(root, 3);

    Node *root1 = new Node(50);
    root1->left = new Node(20);
    root1->right = new Node(60);
    root1->left->left = new Node(10);
    root1->left->right = new Node(30);
    root1->right->left = new Node(55);
    root1->right->right = new Node(70);

    findPredSuccItr(root1, 55);

    return 0;
}
