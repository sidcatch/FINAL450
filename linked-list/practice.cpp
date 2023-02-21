#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data, Node *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

struct LinkList
{
    Node *head;
    //int size;

    LinkList()
    {
        head = nullptr;
    }
    LinkList(Node *h)
    {
        head = h;
    }

    void print()
    {
        Node *p = head;

        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    void push(int x)
    {
        Node *p = new Node(x, head);
        head = p;
    }

    Node *reverseInGroups(Node *current, int x)
    {

        Node *curr = current;
        Node *prev = nullptr;
        Node *next = nullptr;
        int count = 0;

        while (curr && count < x)
        {
            next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
            count++;
        }

        if (next)
            current->next = reverseInGroups(next, x);

        return prev;
    }
};

int main()
{
    LinkList l{};

    l.push(1);
    l.push(2);
    l.push(3);

    l.print();
}