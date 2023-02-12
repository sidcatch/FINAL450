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

struct Queue
{
    Node *front;
    Node *back;

    //int size;

    Queue()
    {
        front = nullptr;
        back = nullptr;
    }
    Queue(Node *h)
    {
        front = h;
    }

    void print()
    {
        Node *p = front;

        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    void enqueue(int x)
    {
        Node *p = new Node(x, nullptr, back);

        if (back)
            back->next = p;
        back = p;

        if (!front)
            front = p;
    }

    Node *dequeue()
    {
        if (front == nullptr)
            return nullptr;

        Node *ret = front;

        front = front->next;

        if (front) //Why do we need?
            front->prev = nullptr;
        ret->next = nullptr;

        return ret;
    }
};

int main()
{
    Queue q{};

    q.enqueue(1);

    q.print();

    cout << q.dequeue()->data << endl;
    // cout << q.dequeue()->data << endl;

    q.enqueue(2);
    q.enqueue(3);

    cout << q.dequeue()->data << endl;
    cout << q.dequeue()->data << endl;

    q.print();
}