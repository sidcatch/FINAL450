#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

struct Queue
{

    Node *front = nullptr;
    Node *back = nullptr;

    void enqueue(int x)
    {
        Node *newNode = new Node(x, nullptr, back);

        if (back)
            back->next = newNode;

        back = newNode;

        if (!front)
            front = newNode;
    }

    Node *dequeue()
    {
        if (front == nullptr)
            return nullptr;

        Node *ret = front;

        front = front->next;

        if (front == nullptr)
            back = nullptr;
        else
            front->prev = nullptr;

        ret->next = nullptr;

        return ret;
    }
};

int main()
{
    Queue q{};

    q.enqueue(1);

    // q.print();

    cout << q.dequeue()->data << endl;
    // cout << q.dequeue()->data << endl;

    q.enqueue(2);
    q.enqueue(3);

    cout << q.dequeue()->data << endl;
    cout << q.dequeue()->data << endl;

    // q.print();
    return 0;
}