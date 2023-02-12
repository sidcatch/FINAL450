#include <iostream>
#include <limits.h>

using namespace std;

struct Queue
{

    static const int maxLimit = 4;
    int elms[maxLimit];

    int front = 0;
    int back = 0;
    int size = 0;

    void enqueue(int x)
    {
        if (size < maxLimit)
        {
            elms[back] = x;
            back--;
            if (back < 0)
                back = maxLimit - 1;
            // cout << back << endl;
            size++;
        }
    }

    int dequeue()
    {
        if (size > 0)
        {
            int ret = elms[front];
            front--;
            if (front < 0)
                front = maxLimit - 1;
            size--;
            return ret;
        }
        return INT_MIN;
    }

    void printArray()
    {
        if (size > 0)
            for (int i = size; i >= 0; i--)
                cout << elms[i] << " ";
        cout << endl;
    }

    bool empty()
    {
        return this->size == 0;
    }
};

int main()
{
    Queue q{};

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    // q.printArray();

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    cout << endl;

    // q.printArray();
}