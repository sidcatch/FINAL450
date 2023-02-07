#include <iostream>
#include <set>
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

    void push(int x)
    {
        Node *p = new Node(x, head);
        head = p;
    }

    void makeLoop(int k)
    {

        Node *p = head;

        Node *x = nullptr;

        int count = 0;
        while (p->next != nullptr)
        {
            p = p->next;
            count++;
            if (count == k)
                x = p;
        }

        p->next = x;
        // head = p;
    }

    Node *findLoop()
    {
        Node *tortise = head;
        Node *hair = head;
        bool loopDetected = false;

        while (hair != nullptr && hair->next != nullptr)
        {
            tortise = tortise->next;
            hair = hair->next->next;

            if (tortise == hair)
            {
                loopDetected = true;
                break;
            }
        }

        if (loopDetected)
        {
            tortise = head;

            while (tortise != hair)
            {
                tortise = tortise->next;
                hair = hair->next;
            }

            return tortise;
        }
        else

            return nullptr;
    }

    Node *findLoopUsingSet()
    {
        set<Node *> seen;

        Node *p = head;
        // seen.insert(p);

        while (p != nullptr)
        {

            if (seen.find(p) != seen.end())
                return p;

            seen.insert(p);
            p = p->next;
        }
        return nullptr;
    }
};

int main()
{
    LinkList l{};

    l.push(1);
    l.push(2);
    l.push(3);
    l.push(1);
    l.push(2);
    l.push(3);

    l.makeLoop(2);

    l.print();

    cout << l.findLoop()->data;
    cout << endl;
    cout << l.findLoopUsingSet()->data;
    cout << endl;
}