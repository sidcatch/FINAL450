//See gfg for only queue based solution.

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

void diagonal(Node *root)
{
    if (root == nullptr)
        return;

    unordered_map<int, vector<Node *>> diagonalGroups;
    int maxDiagonalNum = 0;

    queue<pair<Node *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        Node *curr = q.front().first;
        int diagonalNum = q.front().second;
        q.pop();

        if (maxDiagonalNum < diagonalNum)
            maxDiagonalNum = diagonalNum;

        diagonalGroups[diagonalNum].push_back(curr);

        if (curr->left)
            q.push(make_pair(curr->left, diagonalNum + 1));
        if (curr->right)
            q.push(make_pair(curr->right, diagonalNum));
    }

    for (int i = 0; i <= maxDiagonalNum; i++)
    {
        vector<Node *> diagonalGroup = diagonalGroups[i];

        for (Node *curr : diagonalGroup)
            cout << curr->data << " ";
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // root->right->left = new Node(6);

    cout << "Binary Tree \n";

    diagonal(root);

    return 0;
}
