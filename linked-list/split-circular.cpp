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

    void makeCircle()
    {

        Node *p = head;

        if (p == nullptr)
            return;

        while (p->next != nullptr)
        {
            p = p->next;
        }

        p->next = this->head;
    }

    void print()
    {
        Node *p = head;

        int count = 0;
        while (p != nullptr && count < 20)
        {
            cout << p->data << " ";
            p = p->next;
            count++;
        }
        cout << endl;
    }

    void print(Node *p)
    {
        //Node *p = head;

        int count = 0;
        while (p != nullptr && count < 20)
        {
            cout << p->data << " ";
            p = p->next;
            count++;
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
    l.push(3);

    l.makeCircle();

    l.print();
}