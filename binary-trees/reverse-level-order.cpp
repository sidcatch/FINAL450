#include <iostream>
#include <queue>
#include <stack>

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

void reverseLevelOrder(Node *root)
{
    if (root == nullptr)
        return;

    queue<Node *> q;
    stack<Node *> s;

    q.push(root);

    while (!q.empty())
    {

        Node *current = q.front();
        q.pop();

        s.push(current);

        if (current->right != nullptr)
            q.push(current->right);
        if (current->left != nullptr)
            q.push(current->left);
    }

    while (!s.empty())
    {
        cout << s.top()->data << " ";
        s.pop();
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

    cout << "Binary Tree \n";

    reverseLevelOrder(root);

    return 0;
}

// This code is contributed by rathbhupendra
