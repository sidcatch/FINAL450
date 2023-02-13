#include <iostream>
#include <limits.h>

using namespace std;

struct Stack
{

    static const int maxLimit = 50;
    int elms[maxLimit];

    int top1 = -1;
    int top2 = maxLimit;

    void push1(int x)
    {
        if (top1 < top2 - 1 && top1 < maxLimit)
            elms[++top1] = x;
    }

    int pop1()
    {
        if (!this->empty1())
            return elms[top1--];
        else
            return INT_MIN;
    }

    void print1()
    {
        if (top1 != -1)
            for (int i = top1; i >= 0; i--)
                cout << elms[i] << " ";
        cout << endl;
    }

    bool empty1()
    {
        return this->top1 == -1;
    }

    void push2(int x)
    {
        if (top2 > top1 + 1 && top2 > 0)
            elms[--top2] = x;
    }

    int pop2()
    {
        if (!this->empty2())
            return elms[top2++];
        else
            return INT_MIN;
    }

    void print2()
    {
        if (top2 != maxLimit)
            for (int i = top2; i < maxLimit; i++)
                cout << elms[i] << " ";
        cout << endl;
    }

    bool empty2()
    {
        return top2 == maxLimit;
    }
};

int main()
{
    Stack s{};

    s.push1(1);
    s.push1(2);
    s.push1(3);

    s.print1();

    cout << s.pop1();

    cout << endl;

    s.print1();

    cout << endl;

    s.push2(1);
    s.push2(2);
    s.push2(3);

    s.print2();

    cout << s.pop2();

    cout << endl;

    s.print2();

    cout << endl;
}