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

void topView(Node *root)
{
    if (root == nullptr)
        return;

    // unordered_map<int, vector<Node *>> HDgroups;

    stack<Node *> leftNodesToPrint;
    vector<Node *> rightNodesToPrint;

    queue<pair<Node *, int>> q;

    q.push(make_pair(root, 0));

    int maxL = 0, maxR = 0;

    while (!q.empty())
    {

        Node *curr = q.front().first;
        int HD = q.front().second;
        q.pop();

        if (HD < maxL)
        {
            leftNodesToPrint.push(curr);
            maxL = HD;
        }

        if (HD > maxR)
        {
            rightNodesToPrint.push_back(curr);
            maxR = HD;
        }

        // HDgroups[HD].push_back(curr);

        if (curr->left != nullptr)
            q.push(make_pair(curr->left, HD - 1));

        if (curr->right != nullptr)
            q.push(make_pair(curr->right, HD + 1));
    }

    while (!leftNodesToPrint.empty())
    {
        cout << leftNodesToPrint.top()->data << " ";
        leftNodesToPrint.pop();
    }

    cout << root->data << " ";

    for (Node *curr : rightNodesToPrint)
        cout << curr->data << " ";
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Binary Tree Vertical order transversal\n";

    topView(root);

    return 0;
}
