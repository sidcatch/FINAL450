#include <iostream>
using namespace std;

//See gfg for good solution
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

    void makeLoop()
    {

        if (!head)
            return;

        Node *i = head;
        while (i->next != nullptr)
        {
            i = i->next;
        }

        i->next = head;
    }

    //Wrong!
    int getLoopPointData()
    {
        //if head == nullptr!

        Node *tortise = head;
        Node *rabbit = head;

        while (rabbit && rabbit->next != nullptr)
        {
            rabbit = rabbit->next->next;
            tortise = tortise->next;

            if (rabbit == tortise)
                return rabbit->data;
        }
        return -1;
    }

    //Wrong!
    Node *getLoopPoint()
    {
        //if head == nullptr!

        Node *tortise = head;
        Node *rabbit = head;

        while (rabbit && rabbit->next != nullptr)
        {
            rabbit = rabbit->next->next;
            tortise = tortise->next;

            if (rabbit == tortise)
                return rabbit;
        }
        return nullptr;
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

    Node *find(int x)
    {
        Node *p = head;

        while (p != nullptr)
        {
            if (p->data == x)
                return p;
        }
        return nullptr;
    }

    Node *push(int x)
    {
        Node *p = new Node(x, head);
        head = p;
        return p;
    }

    Node *push(Node *x)
    {
        x->next = head;
        head = x;
        return x;
    }
    Node *setHead(Node *x)
    {
        //x->next = head;
        head = x;
        return x;
    }
};

int main()

{

    LinkList l1{};

    l1.push(new Node(1));
    l1.push(new Node(2));
    l1.push(new Node(3));
    l1.push(new Node(4));
    l1.push(new Node(5));
    Node *link = l1.push(new Node(6));
    l1.push(new Node(7));
    l1.push(new Node(8));
    l1.push(new Node(9));
    l1.print();

    LinkList l2{};

    l2.setHead(link);
    l2.push(new Node(16));
    l2.push(new Node(15));
    l2.push(new Node(17));
    l2.push(new Node(18));
    l2.push(new Node(19));
    l2.print();
    l2.makeLoop();
    //l2.print();

    cout << l1.getLoopPointData() << endl;
    cout << l2.getLoopPointData() << endl;
}