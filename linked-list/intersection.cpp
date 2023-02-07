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

    LinkList intersect(LinkList sec)
    {
        Node *a = this->head;
        Node *b = sec.head;

        Node *res = nullptr;
        Node *temp, *prev = nullptr;

        while (a != nullptr && b != nullptr)
        {
            if (a->data < b->data)
                a = a->next;
            if (b->data < a->data)
                b = b->next;
            else
            {
                temp = new Node(a->data);

                if (res == nullptr)
                    res = temp;
                else
                    prev->next = temp;

                prev = temp;

                a = a->next;
                b = b->next;
            }
        }

        return LinkList(res);
    }

    void reverseIterative()
    {
        Node *current = head;
        Node *next = nullptr;
        Node *prev = nullptr;

        while (current != nullptr)
        {
            next = current->next;

            current->next = prev;

            prev = current;
            current = next;
        }

        head = prev;
    }

    Node *reverseRecursive(Node *current)
    {
        if (current == nullptr || current->next == nullptr)
            return current;

        Node *newHead = reverseRecursive(current->next);

        //reverse
        current->next->next = current;

        //Not doing this will leave a loop at the last node of the reversed list
        current->next = nullptr;

        return newHead;
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
    LinkList l1{};

    l1.push(100);
    l1.push(65);
    l1.push(55);
    l1.push(35);
    l1.push(23);
    l1.push(15);
    l1.push(0);

    l1.print();
    LinkList l2{};

    l2.push(55);
    l2.push(45);
    l2.push(35);
    l2.push(21);
    l2.push(15);
    l2.push(0);

    l2.print();

    LinkList l3 = l1.intersect(l2);

    l3.print();
}