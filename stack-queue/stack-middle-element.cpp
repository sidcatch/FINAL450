#include <deque>
#include <iostream>
#include <stack>

using namespace std;

//For Linked List based solution see gfg
struct Stack
{
    deque<int> dq;
    stack<int> st;

    void push(int x)
    {
        dq.push_back(x);
        if (dq.size() > st.size() + 1)
        {
            int front = dq.front();
            dq.pop_front();
            st.push(front);
        }
    }

    void pop()
    {
        dq.pop_back();
        if (st.size() > dq.size())
        {
            int top = st.top();
            st.pop();
            dq.push_front(top);
        }
    }

    //If even middle element is the top's side
    int getMiddle()
    {
        return dq.front();
    }

    void deleteMiddle()
    {
        dq.pop_front();
        if (st.size() > dq.size())
        {
            int top = st.top();
            st.pop();
            dq.push_front(top);
        }
    }
};

int main()
{
    Stack st;
    st.push(2);
    st.push(5);
    cout << "Middle Element: " << st.getMiddle() << endl;
    st.push(3);
    st.push(7);
    st.push(4);
    cout << "Middle Element: " << st.getMiddle() << endl;
    st.deleteMiddle();
    cout << "Middle Element: " << st.getMiddle() << endl;
    st.deleteMiddle();
    cout << "Middle Element: " << st.getMiddle() << endl;
    st.pop();
    st.pop();
    st.deleteMiddle();
    return 0;
}
