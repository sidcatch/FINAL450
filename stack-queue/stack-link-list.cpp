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

struct Stack
{
    Node *head;
    //int size;

    Stack()
    {
        head = nullptr;
    }
    Stack(Node *h)
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

    Node *pop()
    {
        if (head == nullptr)
            return nullptr;

        Node *ret = head;

        head = head->next;

        return ret;
    }
};

int main()
{
    Stack s{};

    s.push(1);
    s.push(2);
    s.push(3);

    s.print();

    cout << s.pop()->data;

    cout << endl;

    s.print();
}