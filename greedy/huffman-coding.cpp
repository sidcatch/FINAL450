// Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e. character S[i] has f[i] frequency. Your task is to build the Huffman tree print all the huffman codes in preorder traversal of the tree.
// Note: While merging if two nodes have the same value, then the node which occurs at first will be taken on the left of Binary Tree and the other one to the right, otherwise Node with less value will be taken on the left of the subtree and other one to the right.

#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void printStack(stack<int> s)
{
    if (s.empty())
        return;

    int x = s.top();
    s.pop();
    printStack(s);

    cout << x;

    s.push(x);
}

class Node
{
  public:
    /* const */ char *character;
    int frequency;
    Node *left;
    Node *right;

    Node(int f, /* const */ char *c = nullptr, Node *l = nullptr, Node *r = nullptr) : character{c}, frequency{f}, left{l}, right{r}
    {
    }
};

class Comparator
{
  public:
    bool operator()(Node *a, Node *b)
    {
        return a->frequency > b->frequency;
    }
};

void printHuffmanCodes(Node *head)
{

    static stack<int> toPrint;

    if (!head)
        return;

    if (head->left) // An optimal code for a file is always represented by a full binary tree, in which every nonleaf node has two children. So we can just test for left child
    {
        toPrint.push(0);
        printHuffmanCodes(head->left);
        toPrint.pop();
        toPrint.push(1);
        printHuffmanCodes(head->right);
        toPrint.pop();
    }
    else // if (head->character)
    {
        printStack(toPrint);
        cout << " ";
    }
}

int main()
{

    string s = "abcdef";
    int f[] = {5, 9, 12, 13, 16, 45};
    int n = s.size();

    priority_queue<Node *, vector<Node *>, Comparator> minFreqHeap;

    for (int i = 0; i < n; i++)
        minFreqHeap.push(new Node(f[i], &s[i]));

    // In Huffman tree there are n leaf node and n-1 nonleaf node, for each loop we are creating a non-leaf node.
    for (int i = 0; i < n - 1; i++)
    {
        Node *left = minFreqHeap.top();
        minFreqHeap.pop();
        Node *right = minFreqHeap.top();
        minFreqHeap.pop();
        int freq = left->frequency + right->frequency;

        //Make the least frequency nodes children to the new parent, so they fall to the bottom of the tree.
        Node *node = new Node(freq, nullptr, left, right);
        minFreqHeap.push(node);
    }
    //should be 1 Node left now in the minFreqHeap.

    Node *head = minFreqHeap.top();
    minFreqHeap.pop();

    printHuffmanCodes(head);
    cout << endl
         << endl
         << "End";

    return 0;
}