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

//For a method without using linked list see gfg
struct Queue
{
    Node *front = nullptr;
    Node *back = nullptr;
    Node *middle = nullptr;

    int size = 0;

    // Queue()
    // {
    //     front = nullptr;
    //     back = nullptr;
    // }
    // Queue(Node *h)
    // {
    //     front = h;
    // }

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

        if (!middle)
            middle = p;
        else
        {
            if (size % 2 != 0)
            {
                middle = middle->next;
            }
        }

        size++;
    }

    Node *dequeue()
    {
        if (front == nullptr)
            return nullptr;

        Node *ret = front;

        front = front->next;

        if (front == nullptr)
        {
            back = nullptr;
            middle = nullptr;
        }

        else
        {
            front->prev = nullptr;
            if (size % 2 != 0)
            {
                middle = middle->next;
            }
        }

        ret->next = nullptr;

        size--;

        return ret;
    }

    Node *getMiddle()
    {

        return middle;
    }

    void deleteMiddle()
    {
        if (middle == nullptr)
            return;

        Node *toDelete = middle;

        if (middle->next)
            middle->next->prev = middle->prev;
        if (middle->prev)
            middle->prev->next = middle->next;

        if (size % 2 != 0)
            middle = middle->next;
        else
            middle = middle->prev;

        if (middle == nullptr)
        {
            front = nullptr;
            back = nullptr;
        }

        size--;

        delete toDelete;
    }
};

int main()
{
    Queue q{};

    q.enqueue(1);

    // q.print();
    // cout << q.getMiddle()->data << endl;

    // cout << q.dequeue()->data << endl;

    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    // cout << q.dequeue()->data << endl;
    // cout << q.dequeue()->data << endl;
    // cout << q.dequeue()->data << endl;

    q.print();
    cout << q.getMiddle()->data << endl;

    q.deleteMiddle();
    q.print();
    cout << q.getMiddle()->data << endl;

    q.deleteMiddle();
    q.print();
    cout << q.getMiddle()->data << endl;

    q.deleteMiddle();
    q.print();
    cout << q.getMiddle()->data << endl;

    q.deleteMiddle();
    q.print();
    cout << q.getMiddle()->data << endl;

    q.deleteMiddle();

    cout << endl;
}