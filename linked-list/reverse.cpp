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

    void reverseIterative()
    {
        Node *current = head;
        Node *next = nullptr;
        Node *prev = nullptr;

        while (current != nullptr)
        {
            next = current->next;

            current->next = prev;

            prev = current;
            current = next;
        }

        head = prev;
    }

    Node *reverseRecursive(Node *current)
    {
        if (current == nullptr || current->next == nullptr)
            return current;

        Node *newHead = reverseRecursive(current->next);

        //reverse
        current->next->next = current;

        //Not doing this will leave a loop at the last node of the reversed list
        current->next = nullptr;

        return newHead;
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
};

int main()
{
    LinkList l{};

    l.push(1);
    l.push(5);
    l.push(2);
    l.push(3);

    l.print();

    l.head = l.reverseRecursive(l.head);
    l.print();
}