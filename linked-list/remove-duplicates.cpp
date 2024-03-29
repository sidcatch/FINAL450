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

    void removeDuplicatesSorted()
    {
        if (head == nullptr)
            return;

        Node *current = head;

        while (current != nullptr && current->next != nullptr)
        {
            if (current->data == current->next->data)
            {
                Node *nextToNext = current->next->next;

                delete current->next;

                current->next = nextToNext;
            }
            else
                current = current->next;
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

    void push(int x)
    {
        Node *p = new Node(x, head);
        head = p;
    }
};

int main()
{
    LinkList l{};

    l.push(9);
    l.push(6);
    l.push(5);
    l.push(5);
    l.push(3);
    l.push(3);
    l.push(3);
    l.push(2);
    l.push(1);

    l.print();

    l.removeDuplicatesSorted();

    l.print();
}