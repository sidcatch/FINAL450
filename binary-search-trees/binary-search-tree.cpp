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

Node *find(Node *root, int x)
{
    if (root == nullptr)
        return nullptr;

    if (x < root->data)
        return find(root->left, x);
    else if (x > root->data)
        return find(root->right, x);
    else
        return root;
}

Node *findItr(Node *root, int x)
{
    Node *curr = root;

    while (curr != nullptr)
    {
        if (x < curr->data)
            curr = curr->left;
        else if (x > curr->data)
            curr = curr->right;
        else
            return curr;
    }
    return nullptr;
}

Node *findMin(Node *root)
{
    if (root == nullptr || root->left == nullptr)
        return root;

    else
        return findMin(root->left);
}

Node *findMinItr(Node *root)
{
    Node *curr = root;

    if (curr == nullptr)
        return curr;

    while (curr->left != nullptr)
    {
        curr = curr->left;
    }

    return curr;
}

bool deleteNode(Node *&root, int x) //Notice! reference to pointer
{
    if (root == nullptr)
        return false;

    if (x < root->data)
        return deleteNode(root->left, x);
    else if (x > root->data)
        return deleteNode(root->right, x);
    else if (root->left != nullptr && root->right != nullptr)
    {
        Node *minInRight = findMin(root->right);

        root->data = minInRight->data;
        // minInRight->data = x;

        return deleteNode(root->right, root->data);
    }
    else
    {

        Node *oldNode = root;

        root = root->left != nullptr ? root->left : root->right;

        delete oldNode;

        return true;
    }
}

bool deleteNodeItr(Node *&root, int x)
{
    Node *curr = root;
    Node *prev = nullptr;

    int y = x;

    while (curr != nullptr)
    {

        if (y < curr->data)
        {
            prev = curr;
            curr = curr->left;
        }

        else if (y > curr->data)
        {
            prev = curr;
            curr = curr->right;
        }

        else if (curr->left != nullptr && curr->right != nullptr)
        {
            Node *minInRight = findMinItr(curr->right);

            curr->data = minInRight->data;
            prev = curr;
            curr = curr->right;
            y = curr->data;
        }
        else
        {
            if (prev)
            {
                if (prev->right && prev->right == curr)
                    prev->right = curr->left != nullptr ? curr->left : curr->right;
                else if (prev->left && prev->left == curr)
                    prev->left = curr->left != nullptr ? curr->left : curr->right;
            }
            else
                root = nullptr;

            delete curr;
            return true;
        }
    }
    return false;
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

    Node *found = find(root, 3);

    if (found)
        cout << found->data << " " << endl;
    else
        cout << "Not found" << endl;

    cout << "Min elemnt: " << findMin(root)->data << endl;

    inorder(root);
    cout << endl;

    deleteNodeItr(root, 4);
    inorder(root);
    cout << endl;

    Node *found2 = find(root, 2);

    if (found2)
        cout << found2->data << " " << endl;
    else
        cout << "Not found" << endl;

    return 0;
}
