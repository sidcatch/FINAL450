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
    LinkList(Node *h)
    {
        head = h;
    }

    void isPalindrome()
    {

        if (head == nullptr || head->next == nullptr)
            return;

        Node *rabbit = head;
        Node *tortise = head;

        Node *prev = nullptr, *next = nullptr;

        Node *nextStore = nullptr;

        while (rabbit /* ->next */ != nullptr && rabbit->next /* ->next */ != nullptr)
        {
            nextStore = next;
            next = tortise->next;

            rabbit = rabbit->next->next;
            tortise->next = prev;

            prev = tortise;
            tortise = next;
        }

        if (rabbit != nullptr)
            tortise = tortise->next;

        while (tortise != nullptr)
        {
            cout << tortise->data << " ";
            tortise = tortise->next;
        }
        cout << endl;

        while (nextStore != nullptr)
        {
            cout << nextStore->data << " ";
            nextStore = nextStore->next;
        }
        cout << endl;
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
    l.push(8);
    //l.push(9);

    l.print();

    l.isPalindrome();
}