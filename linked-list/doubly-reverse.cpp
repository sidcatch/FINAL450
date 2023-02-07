#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int data, Node *next = nullptr, Node *prev = nullptr)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

struct DoublyLinkList
{
    Node *head;
    Node *tail;

    DoublyLinkList()
    {
        head = nullptr;
        tail = nullptr;
    }
    DoublyLinkList(Node *h, Node *t)
    {
        head = h;
        tail = t;
    }

    void reverse()
    {
        if (head == nullptr || head->next == nullptr)
            return;

        Node *current = head;

        while (current != tail)
        {
            Node *next = current->next;
            current->next = current->prev;
            current->prev = next;
        }
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
    void printReverse()
    {
        Node *p = tail;

        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->prev;
        }
        cout << endl;
    }

    void push(int x)
    {
        Node *p = new Node(x, head);
        if (head != nullptr)
        {
            head->prev = p;
        }
        else
        {
            tail = p;
        }

        head = p;
    }
};

int main()
{
    DoublyLinkList l{};

    l.push(1);
    l.push(2);
    l.push(3);

    l.print();
    l.printReverse();
}