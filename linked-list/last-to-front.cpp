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

    void lastToFront()
    {
        if (head == nullptr || head->next == nullptr)
            return;

        Node *current = head;

        while (current->next->next != nullptr)
        {
            current = current->next;
        }

        current->next->next = head;
        head = current->next;
        current->next = nullptr;
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
    l.push(2);
    // l.push(3);
    // l.push(4);

    l.print();

    l.lastToFront();
    l.print();
}