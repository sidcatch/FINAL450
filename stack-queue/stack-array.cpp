#include <iostream>
#include <limits.h>

using namespace std;

struct Stack
{

    static const int maxLimit = 50;
    int elms[maxLimit];

    int top = -1;

    void push(int x)
    {
        if (top < maxLimit)
            elms[++top] = x;
    }

    int pop()
    {
        if (!this->empty())
            return elms[top--];
        else
            return INT_MIN;
    }

    void print()
    {
        if (top != -1)
            for (int i = top; i >= 0; i--)
                cout << elms[i] << " ";
        cout << endl;
    }

    bool empty()
    {
        return this->top == -1;
    }
};

int main()
{
    Stack s{};

    s.push(1);
    s.push(2);
    s.push(3);

    s.print();

    cout << s.pop();

    cout << endl;

    s.print();
}