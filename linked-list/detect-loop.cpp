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

struct LinkList
{
    Node *head;
    //int size;

    LinkList()
    {
        head = nullptr;
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

    bool hasLoop()
    {
        //if head == nullptr!

        Node *tortise = head;
        Node *rabbit = head;

        while (rabbit && rabbit->next != nullptr)
        {
            rabbit = rabbit->next->next;
            tortise = tortise->next;

            if (rabbit == tortise)
                return true;
        }
        return false;
    }

    void deleteLoop()
    {
        if (head == nullptr || head->next == nullptr)
            return;

        Node *slow = head;
        Node *fast = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (slow == fast)
                break;
        }

        if (slow == fast)
        {
            slow = head;

            if (slow == fast)
            {
                while (fast->next != slow)
                    fast = fast->next;
            }
            else
            {
                while (fast->next != slow->next)
                {
                    fast = fast->next;
                    slow = fast->next;
                }
            }

            fast->next = nullptr;
        }
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
};

int main()
{
    LinkList l{};

    l.push(1);
    l.push(2);
    l.push(3);
    l.push(7);
    l.push(2);
    l.push(8);
    l.push(1);
    l.push(4);
    l.push(6);

    l.print();

    cout << l.hasLoop() << endl;
}